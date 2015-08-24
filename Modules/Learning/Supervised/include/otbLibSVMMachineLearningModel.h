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
#ifndef __otbLibSVMMachineLearningModel_h
#define __otbLibSVMMachineLearningModel_h

#include "itkLightObject.h"
#include "itkFixedArray.h"
#include "otbMachineLearningModel.h"

// SVM estimator
#include "otbSVMSampleListModelEstimator.h"
// Validation
#include "otbSVMClassifier.h"

namespace otb
{
template <class TInputValue, class TTargetValue>
class ITK_EXPORT LibSVMMachineLearningModel
  : public MachineLearningModel <TInputValue, TTargetValue>
{
public:
  /** Standard class typedefs. */
  typedef LibSVMMachineLearningModel           Self;
  typedef MachineLearningModel<TInputValue, TTargetValue> Superclass;
  typedef itk::SmartPointer<Self>                         Pointer;
  typedef itk::SmartPointer<const Self>                   ConstPointer;

  // Input related typedefs
  typedef TInputValue                                     InputValueType;
  typedef itk::VariableLengthVector<InputValueType>       InputSampleType;
  typedef itk::Statistics::ListSample<InputSampleType>    InputListSampleType;

  // Target related typedefs
  typedef TTargetValue                                    TargetValueType;
  typedef itk::FixedArray<TargetValueType,1>              TargetSampleType;
  typedef itk::Statistics::ListSample<TargetSampleType>   TargetListSampleType;

  // LibSVM related typedefs
  typedef otb::Functor::VariableLengthVectorToMeasurementVectorFunctor<InputSampleType> MeasurementVectorFunctorType;
  typedef otb::SVMSampleListModelEstimator<InputListSampleType, TargetListSampleType, MeasurementVectorFunctorType>
      SVMEstimatorType;

  typedef otb::SVMClassifier<InputSampleType, TargetValueType> ClassifierType;

  /** Run-time type information (and related methods). */
  itkNewMacro(Self);
  itkTypeMacro(SVMMachineLearningModel, itk::MachineLearningModel);

  /** Train the machine learning model */
  virtual void Train();

  /** Predict values using the model */
  virtual TargetSampleType Predict(const InputSampleType & input) const;

  /** Save the model to file */
  virtual void Save(const std::string &filename, const std::string & name="");

  /** Load the model from file */
  virtual void Load(const std::string & filename, const std::string & name="");

  /**\name Classification model file compatibility tests */
  //@{
  /** Is the input model file readable and compatible with the corresponding classifier ? */
  virtual bool CanReadFile(const std::string &);

  /** Is the input model file writable and compatible with the corresponding classifier ? */
  virtual bool CanWriteFile(const std::string &);
  //@}

  //Setters/Getters to SVM model
  // itkGetMacro(SVMType, int);
  // itkSetMacro(SVMType, int);

  itkGetMacro(KernelType, int);
  itkSetMacro(KernelType, int);

  itkGetMacro(C, float);
  itkSetMacro(C, float);

  itkGetMacro(ParameterOptimization, bool);
  itkSetMacro(ParameterOptimization, bool);
 
  itkGetMacro(DoProbabilityEstimates, bool);
  itkSetMacro(DoProbabilityEstimates, bool);

  // itkGetMacro(Epsilon, int);
  // itkSetMacro(Epsilon, int);

protected:
  /** Constructor */
  LibSVMMachineLearningModel();

  /** Destructor */
  virtual ~LibSVMMachineLearningModel();

  /** PrintSelf method */
  void PrintSelf(std::ostream& os, itk::Indent indent) const;

private:
  LibSVMMachineLearningModel(const Self &); //purposely not implemented
  void operator =(const Self&); //purposely not implemented

  int m_KernelType;
  float m_C;
  bool m_ParameterOptimization;
  bool m_DoProbabilityEstimates;
  typename SVMEstimatorType::Pointer m_SVMestimator;
};
} // end namespace otb

#ifndef OTB_MANUAL_INSTANTIATION
#include "otbLibSVMMachineLearningModel.txx"
#endif

#endif
