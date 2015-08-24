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
#ifndef __otbWrapperQtWidgetInputFilenameParameter_h
#define __otbWrapperQtWidgetInputFilenameParameter_h

#include <QtGui>
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829  //tag=QT4-boost-compatibility
#include "otbWrapperInputFilenameParameter.h"
#include "otbWrapperQtWidgetParameterBase.h"
#endif //tag=QT4-boost-compatibility


namespace otb
{
namespace Wrapper
{

/** \class QtWidgetInputFilenameParameter
 * \brief
 *
 * \ingroup OTBQtWidget
 */
class ITK_ABI_EXPORT QtWidgetInputFilenameParameter : public QtWidgetParameterBase
{
  Q_OBJECT
public:
  QtWidgetInputFilenameParameter(InputFilenameParameter*, QtWidgetModel*);
  virtual ~QtWidgetInputFilenameParameter();

  inline const QLineEdit* GetInput() const;
  inline QLineEdit* GetInput();

protected slots:
  void SetFileName( const QString& value );
  void SelectFile();

private:
  QtWidgetInputFilenameParameter(const QtWidgetInputFilenameParameter&); //purposely not implemented
  void operator=(const QtWidgetInputFilenameParameter&); //purposely not implemented

  virtual void DoCreateWidget();

  virtual void DoUpdateGUI();


  InputFilenameParameter::Pointer m_FilenameParam;

  QHBoxLayout * m_HLayout;
  QLineEdit*    m_Input;
  QPushButton * m_Button;
};


inline
const QLineEdit*
QtWidgetInputFilenameParameter
::GetInput() const
{
  return m_Input;
}

inline
QLineEdit*
QtWidgetInputFilenameParameter
::GetInput()
{
  return m_Input;
}

} // Wrapper

} // otb

#endif
