/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __otbImageClassificationFilter_txx
#define __otbImageClassificationFilter_txx

#include "otbImageClassificationFilter.h"
#include "itkImageRegionIterator.h"
#include "itkProgressReporter.h"

namespace otb
{
/**
 * Constructor
 */
template <class TInputImage, class TOutputImage, class TMaskImage>
ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::ImageClassificationFilter()
{
  this->SetNumberOfIndexedInputs(2);
  this->SetNumberOfRequiredInputs(1);
  m_DefaultLabel = itk::NumericTraits<LabelType>::ZeroValue();

  this->SetNumberOfRequiredOutputs(2);
  this->SetNthOutput(0,TOutputImage::New());
  this->SetNthOutput(1,ConfidenceImageType::New());
  m_UseConfidenceMap = false;
}

template <class TInputImage, class TOutputImage, class TMaskImage>
void
ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::SetInputMask(const MaskImageType * mask)
{
  this->itk::ProcessObject::SetNthInput(1, const_cast<MaskImageType *>(mask));
}

template <class TInputImage, class TOutputImage, class TMaskImage>
const typename ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::MaskImageType *
ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::GetInputMask()
{
  if (this->GetNumberOfInputs() < 2)
    {
    return 0;
    }
  return static_cast<const MaskImageType *>(this->itk::ProcessObject::GetInput(1));
}

template <class TInputImage, class TOutputImage, class TMaskImage>
typename ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::ConfidenceImageType *
ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::GetOutputConfidence()
{
  if (this->GetNumberOfOutputs() < 2)
    {
    return 0;
    }
  return static_cast<ConfidenceImageType *>(this->itk::ProcessObject::GetOutput(1));
}

template <class TInputImage, class TOutputImage, class TMaskImage>
void
ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::BeforeThreadedGenerateData()
{
  if (!m_Model)
    {
    itkGenericExceptionMacro(<< "No model for classification");
    }
}

template <class TInputImage, class TOutputImage, class TMaskImage>
void
ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread, itk::ThreadIdType threadId)
{
  // Get the input pointers
  InputImageConstPointerType inputPtr     = this->GetInput();
  MaskImageConstPointerType  inputMaskPtr  = this->GetInputMask();
  OutputImagePointerType     outputPtr    = this->GetOutput();
  ConfidenceImagePointerType confidencePtr = this->GetOutputConfidence();

  // Progress reporting
  itk::ProgressReporter progress(this, threadId, outputRegionForThread.GetNumberOfPixels());

  // Define iterators
  typedef itk::ImageRegionConstIterator<InputImageType> InputIteratorType;
  typedef itk::ImageRegionConstIterator<MaskImageType>  MaskIteratorType;
  typedef itk::ImageRegionIterator<OutputImageType>     OutputIteratorType;
  typedef itk::ImageRegionIterator<ConfidenceImageType> ConfidenceMapIteratorType;

  InputIteratorType inIt(inputPtr, outputRegionForThread);
  OutputIteratorType outIt(outputPtr, outputRegionForThread);

  // Eventually iterate on masks
  MaskIteratorType maskIt;
  if (inputMaskPtr)
    {
    maskIt = MaskIteratorType(inputMaskPtr, outputRegionForThread);
    maskIt.GoToBegin();
    }

  // setup iterator for confidence map
  bool computeConfidenceMap(m_UseConfidenceMap && m_Model->HasConfidenceIndex() && !m_Model->GetRegressionMode());
  ConfidenceMapIteratorType confidenceIt;
  if (computeConfidenceMap)
    {
    confidenceIt = ConfidenceMapIteratorType(confidencePtr,outputRegionForThread);
    confidenceIt.GoToBegin();
    }

  bool validPoint = true;
  double confidenceIndex = 0.0;

  // Walk the part of the image
  for (inIt.GoToBegin(), outIt.GoToBegin(); !inIt.IsAtEnd() && !outIt.IsAtEnd(); ++inIt, ++outIt)
    {
    // Check pixel validity
    if (inputMaskPtr)
      {
      validPoint = maskIt.Get() > 0;
      ++maskIt;
      }
    // If point is valid
    if (validPoint)
      {
      // Classifify
      if (computeConfidenceMap)
        {
        outIt.Set(m_Model->Predict(inIt.Get(),&confidenceIndex)[0]);
        }
      else
        {
        outIt.Set(m_Model->Predict(inIt.Get())[0]);
        }
      }
    else
      {
      // else, set default value
      outIt.Set(m_DefaultLabel);
      confidenceIndex = 0.0;
      }
    if (computeConfidenceMap)
      {
      confidenceIt.Set(confidenceIndex);
      ++confidenceIt;
      }
    progress.CompletedPixel();
    }

}
/**
 * PrintSelf Method
 */
template <class TInputImage, class TOutputImage, class TMaskImage>
void
ImageClassificationFilter<TInputImage, TOutputImage, TMaskImage>
::PrintSelf(std::ostream& os, itk::Indent indent) const
{
  Superclass::PrintSelf(os, indent);
}
} // End namespace otb
#endif
