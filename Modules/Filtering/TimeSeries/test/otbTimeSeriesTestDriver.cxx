#include "otbTestMain.h"
void RegisterTests()
{
  REGISTER_TEST(otbEnvelopeSavitzkyGolayInterpolationFunctorTest);
  REGISTER_TEST(otbPolynomialTimeSeriesTest);
  REGISTER_TEST(otbSavitzkyGolayInterpolationFunctorNew);
  REGISTER_TEST(otbSavitzkyGolayInterpolationFunctorTest);
  REGISTER_TEST(otbTimeSeriesLeastSquareFittingFunctorNew);
  REGISTER_TEST(otbTimeSeriesLeastSquareFittingFunctorTest);
  REGISTER_TEST(otbTimeSeriesLeastSquareFittingFunctorWeightsTest);
}
