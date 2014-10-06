#ifdef WIN32
#define CPL_DISABLE_DLL
#endif
#include "ogr_api.h"

int main(int argc,char * argv[])
{
  OGRDataSourceH	hDS;
  OGRSFDriverH        *pahDriver;
  
  OGRRegisterAll(); 	

  hDS = OGROpen(argv[1], FALSE, pahDriver );

  if( hDS == NULL )
    {
    return -1;
    }

  OGRReleaseDataSource( hDS );
  
  return 0;
}
