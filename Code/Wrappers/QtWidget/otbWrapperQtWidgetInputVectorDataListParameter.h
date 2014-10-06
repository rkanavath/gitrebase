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
#ifndef __otbWrapperQtWidgetInputVectorDataListParameter_h
#define __otbWrapperQtWidgetInputVectorDataListParameter_h

#include <QtGui>
#include "otbWrapperInputVectorDataListParameter.h"
#include "otbWrapperQtWidgetParameterBase.h"
#include "otbQtFileSelectionWidget.h"

namespace otb
{
namespace Wrapper
{

/** \class
 * \brief
 */
class ITK_ABI_EXPORT QtWidgetInputVectorDataListParameter : public QtWidgetParameterBase
{
  Q_OBJECT
public:
  QtWidgetInputVectorDataListParameter(InputVectorDataListParameter*, QtWidgetModel*);
  virtual ~QtWidgetInputVectorDataListParameter();


signals:
  void Change();
  void FileSelectionWidgetAdded( QWidget * );

protected slots:
  //void SetFileName( const QString& value );
  //virtual void SelectFile();
  virtual void UpFile();
  virtual void DownFile();
  virtual void AddFile();
  virtual void SupressFile();
  virtual void EraseFile();
  virtual void UpdateVectorDataList();

private:
  QtWidgetInputVectorDataListParameter(const QtWidgetInputVectorDataListParameter&); //purposely not implemented
  void operator=(const QtWidgetInputVectorDataListParameter&); //purposely not implemented

  virtual void DoCreateWidget();

  virtual void DoUpdateGUI();

  void RecreateVectorDataList();
  void UpdateFileList( std::map<unsigned int, unsigned int> idMap );

  InputVectorDataListParameter::Pointer m_InputVectorDataListParam;

  QHBoxLayout * m_HLayout;
  QVBoxLayout * m_FileLayout;
  QScrollArea * m_Scroll;
  std::vector<QtFileSelectionWidget *> m_FileSelectionList;
};


}
}

#endif
