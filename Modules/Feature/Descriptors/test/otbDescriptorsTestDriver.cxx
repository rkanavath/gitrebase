#include "otbTestMain.h"
void RegisterTests()
{
  REGISTER_TEST(otbImageToSURFKeyPointSetFilterOutputDescriptorAscii);
  REGISTER_TEST(otbKeyPointSetsMatchingFilterNew);
  REGISTER_TEST(otbImageToSIFTKeyPointSetFilterOutputInterestPointAscii);
  REGISTER_TEST(otbHistogramOfOrientedGradientCovariantImageFunctionNew);
  REGISTER_TEST(otbHistogramOfOrientedGradientCovariantImageFunction);
  REGISTER_TEST(otbImageToSURFKeyPointSetFilterOutputInterestPointAscii);
  REGISTER_TEST(otbImageToSURFKeyPointSetFilterNew);
  REGISTER_TEST(otbLandmarkNew);
  REGISTER_TEST(otbImageToSIFTKeyPointSetFilterNew);
  REGISTER_TEST(otbKeyPointSetsMatchingFilter);
  REGISTER_TEST(otbImageToSIFTKeyPointSetFilterOutputDescriptorAscii);
  REGISTER_TEST(otbImageToSIFTKeyPointSetFilterOutputAscii);
  REGISTER_TEST(otbFourierMellinImageFilter);
  REGISTER_TEST(otbImageToHessianDeterminantImageFilter);
  REGISTER_TEST(otbImageToSIFTKeyPointSetFilterOutputImage);
  REGISTER_TEST(otbFourierMellinDescriptorsNew);
  REGISTER_TEST(otbFourierMellinDescriptors);
  REGISTER_TEST(otbFourierMellinDescriptorsScaleInvariant);
  REGISTER_TEST(otbFourierMellinDescriptorsRotationInvariant);
  REGISTER_TEST(otbImageToSIFTKeyPointSetFilterDistanceMap);
  REGISTER_TEST(otbImageToHessianDeterminantImageFilterNew);
  REGISTER_TEST(otbFourierMellinImageFilterNew);
#ifdef OTB_USE_SIFTFAST
  REGISTER_TEST(otbImageToFastSIFTKeyPointSetFilterNew);
  REGISTER_TEST(otbImageToFastSIFTKeyPointSetFilterOutputInterestPointAscii);
  REGISTER_TEST(otbImageToFastSIFTKeyPointSetFilterOutputDescriptorAscii);
#endif
}
