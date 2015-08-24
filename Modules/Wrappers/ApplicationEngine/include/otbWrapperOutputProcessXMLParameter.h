#ifndef __otbWrapperOutputProcessXMLParameter_h
#define __otbWrapperOutputProcessXMLParameter_h
#include "otbWrapperApplication.h"
#include "otb_tinyxml.h"

namespace otb
{
namespace Wrapper
{

/** \class OutputProcessXMLParameter
 *  \brief This class represent a xml filename parameter for the wrapper framework to save otb application.
 *
 * \ingroup OTBApplicationEngine
 */
class ITK_ABI_EXPORT OutputProcessXMLParameter
  : public Parameter
{
public:
  /** Standard class typedef */
  typedef OutputProcessXMLParameter     Self;
  typedef Parameter                     Superclass;
  typedef itk::SmartPointer<Self>       Pointer;
  typedef itk::SmartPointer<const Self> ConstPointer;

  /** Defining ::New() static method */
  itkNewMacro(Self);

  /** RTTI support */
  itkTypeMacro(OutputProcessXMLParameter, Parameter);

  itkGetStringMacro(FileName);

  // Set FileName
  void SetFileName(std::string value)
  {
    this->SetValue(value);
  }

  // Set Value
  virtual void SetValue(const std::string value)
    {
    itkDebugMacro("setting member m_FileName to " << value);
    this->m_FileName = value;
    SetActive(true);
    this->Modified();
    }

  bool HasValue() const
  {
    if(m_FileName.empty())
      return false;
    else
      return true;
  }

  void ClearValue()
  {
    m_FileName = "";
  }

  TiXmlElement* AddChildNodeTo(TiXmlElement* parent, std::string name, std::string value="");

  std::string pixelTypeToString(ImagePixelType pixType);

  ParameterType GetParameterType(const Parameter* param) const;

  void Write(Application::Pointer application);

protected:

  OutputProcessXMLParameter();

  /** Destructor */
  virtual ~OutputProcessXMLParameter();

private:

  std::string    m_FileName;

  OutputProcessXMLParameter(const OutputProcessXMLParameter &); //purposely not implemented
  void operator =(const OutputProcessXMLParameter&); //purposely not implemented


}; // End class Parameter

} // End namespace Wrapper
} // End namespace otb

#endif
