set(DOCUMENTATION "This module contains features to read and write MSTAR format
images.")

otb_module(OTBIOMSTAR
  DEPENDS
    OTBImageBase
    OTBCommon
    OTBITK

  TEST_DEPENDS
    OTBTestKernel

  DESCRIPTION
    "${DOCUMENTATION}"
)
