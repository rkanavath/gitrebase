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

  typedef typename Superclass::InputValueType             InputValueType;
  typedef typename Superclass::InputSampleType            InputSampleType;
  typedef typename Superclass::InputListSampleType        InputListSampleType;
  typedef typename Superclass::TargetValueType            TargetValueType;
  typedef typename Superclass::TargetSampleType           TargetSampleType;
  typedef typename Superclass::TargetListSampleType       TargetListSampleType;
  typedef typename Superclass::ConfidenceValueType        ConfidenceValueType;

  // LibSVM related typedefs
  typedef otb::Functor::VariableLengthVectorToMeasurementVectorFunctor<InputSampleType> MeasurementVectorFunctorType;
  typedef otb::SVMSampleListModelEstimator<InputListSampleType, TargetListSampleType, MeasurementVectorFunctorType>
      SVMEstimatorType;

  typedef otb::SVMClassifier<InputSampleType, TargetValueType> ClassifierType;

  /** Run-time type information (and related methods). */
  itkNewMacro(Self);
  itkTypeMacro(SVMMachineLearningModel, MachineLearningModel);

  /** Train the machine learning model */
  virtual void Train();
  /** Predict values using the model */
  virtual TargetSampleType Predict(const InputSampleType& input, ConfidenceValueType *quality=NULL) const;

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
  otbGetObjectMemberMacro(SVMestimator, SVMType, int);
  otbSetObjectMemberMacro(SVMestimator, SVMType, int);

  otbGetObjectMemberMacro(SVMestimator, KernelType, int);
  otbSetObjectMemberMacro(SVMestimator, KernelType, int);

  otbGetObjectMemberMacro(SVMestimator, C, double);
  otbSetObjectMemberMacro(SVMestimator, C, double);

  // TODO : we should harmonize this parameter name : ParameterOptimization -> ParametersOptimization
  bool GetParameterOptimization()
    {
    return this->m_SVMestimator->GetParametersOptimization();
    }
  void SetParameterOptimization(bool value)
    {
    this->m_SVMestimator->SetParametersOptimization(value);
    this->Modified();
    }

  otbGetObjectMemberMacro(SVMestimator, DoProbabilityEstimates, bool);
  void SetDoProbabilityEstimates(bool value)
    {
    this->m_SVMestimator->DoProbabilityEstimates(value);
    }

  otbGetObjectMemberMacro(SVMestimator, Epsilon, double);
  otbSetObjectMemberMacro(SVMestimator, Epsilon, double);

  otbGetObjectMemberMacro(SVMestimator, P, double);
  otbSetObjectMemberMacro(SVMestimator, P, double);

  otbGetObjectMemberMacro(SVMestimator, Nu, double);
  otbSetObjectMemberMacro(SVMestimator, Nu, double);

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

  typename SVMEstimatorType::Pointer m_SVMestimator;
};
} // end namespace otb

#ifndef OTB_MANUAL_INSTANTIATION
#include "otbLibSVMMachineLearningModel.txx"
#endif

#endif
