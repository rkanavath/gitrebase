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
#ifndef __otbWrapperQtWidgetInputImageParameter_h
#define __otbWrapperQtWidgetInputImageParameter_h

#include <QtGui>
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829  //tag=QT4-boost-compatibility
#include "otbWrapperInputImageParameter.h"
#include "otbWrapperQtWidgetParameterBase.h"
#endif //tag=QT4-boost-compatibility


namespace otb
{
namespace Wrapper
{

/** \class QtWidgetInputImageParameter
 * \brief
 *
 * \ingroup OTBQtWidget
 */
class ITK_ABI_EXPORT QtWidgetInputImageParameter : public QtWidgetParameterBase
{
  Q_OBJECT
public:
  QtWidgetInputImageParameter(InputImageParameter*, QtWidgetModel*);
  virtual ~QtWidgetInputImageParameter();

  inline const QLineEdit* GetInput() const;
  inline QLineEdit* GetInput();

protected slots:
  bool SetFileName( const QString& value );
  void SelectFile();

private:
  QtWidgetInputImageParameter(const QtWidgetInputImageParameter&); //purposely not implemented
  void operator=(const QtWidgetInputImageParameter&); //purposely not implemented

  virtual void DoCreateWidget();

  virtual void DoUpdateGUI();


  InputImageParameter::Pointer m_InputImageParam;

  QHBoxLayout * m_HLayout;
  QLineEdit*    m_Input;
  QPushButton * m_Button;
};

inline
const QLineEdit*
QtWidgetInputImageParameter
::GetInput() const
{
  return m_Input;
}

inline
QLineEdit*
QtWidgetInputImageParameter
::GetInput()
{
  return m_Input;
}

} // Wrapper

} // otb

#endif
