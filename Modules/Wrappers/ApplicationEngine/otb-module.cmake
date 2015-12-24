set(DOCUMENTATION "This module contains classes that ease the implementation of
applications (see chapter 'How to write an application' of the SoftwareGuide).")

otb_module(OTBApplicationEngine
  DEPENDS
    OTBVectorDataBase
    OTBImageIO
    OTBProjection
    OTBVectorDataIO
    OTBTransform
    OTBImageManipulation
    OTBTinyXML
    OTBImageBase
    OTBCommon
    OTBObjectList
    OTBBoostAdapters
    OTBOSSIMAdapters
    OTBITK

  TEST_DEPENDS
    OTBTestKernel
    OTBCommandLine
    OTBEdge
    OTBAppImageUtils

  DESCRIPTION
    "${DOCUMENTATION}"
)
