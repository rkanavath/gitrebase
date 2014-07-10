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



#include "itkMacro.h"
#include <iostream>

#include "otbImage.h"
#include "otbImageFileReader.h"
#include "otbImageFileWriter.h"
#include "otbPixelSuppressionByDirectionImageFilter.h"

int otbPixelSuppressionByDirectionNew(int argc, char* argv[])
{
  typedef double InputPixelType;
  typedef double OutputPixelType;
  const unsigned int Dimension = 2;

  typedef otb::Image<InputPixelType,  Dimension> InputImageType;
  typedef otb::Image<OutputPixelType, Dimension> OutputImageType;

  typedef otb::ImageFileReader<InputImageType>  ReaderType1;
  typedef otb::ImageFileReader<InputImageType>  ReaderType2;
  typedef otb::ImageFileWriter<OutputImageType> WriterType;

  typedef otb::PixelSuppressionByDirectionImageFilter<InputImageType, OutputImageType> FilterType;

  FilterType::Pointer filter = FilterType::New();

  std::cout << filter << std::endl;

  return EXIT_SUCCESS;
}
