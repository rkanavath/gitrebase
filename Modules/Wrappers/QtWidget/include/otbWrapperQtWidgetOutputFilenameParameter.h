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
#ifndef __otbWrapperQtWidgetOutputFilenameParameter_h
#define __otbWrapperQtWidgetOutputFilenameParameter_h

#include <QtGui>
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829  //tag=QT4-boost-compatibility
#include "otbWrapperOutputFilenameParameter.h"
#include "otbWrapperQtWidgetParameterBase.h"
#endif //tag=QT4-boost-compatibility


namespace otb
{
namespace Wrapper
{

/** \class QtWidgetOutputFilenameParameter
 * \brief
 *
 * \ingroup OTBQtWidget
 */
class ITK_ABI_EXPORT QtWidgetOutputFilenameParameter : public QtWidgetParameterBase
{
  Q_OBJECT
public:
  QtWidgetOutputFilenameParameter(OutputFilenameParameter*, QtWidgetModel*);
  virtual ~QtWidgetOutputFilenameParameter();

protected slots:
  void SetFileName( const QString& value );
  void SelectFile();

private:
  QtWidgetOutputFilenameParameter(const QtWidgetOutputFilenameParameter&); //purposely not implemented
  void operator=(const QtWidgetOutputFilenameParameter&); //purposely not implemented

  virtual void DoCreateWidget();

  virtual void DoUpdateGUI();


  OutputFilenameParameter::Pointer m_FilenameParam;

  QHBoxLayout * m_HLayout;
  QLineEdit*    m_Input;
  QPushButton * m_Button;
};


}
}

#endif
