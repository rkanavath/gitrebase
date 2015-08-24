set(proj FFTW)

if(NOT __EXTERNAL_${proj}__)
set(__EXTERNAL_${proj}__ 1)

message(STATUS "Setup FFTW ...")

if(USE_SYSTEM_FFTW)
  # TODO : use ITK's FindFFTW
  #find_package ( FFTW )
  add_custom_target(${proj})
  message(STATUS "  Using FFTW system version")
else()
  SETUP_SUPERBUILD(PROJECT ${proj})
  set(projFloat ${proj}F)
  set(projDouble ${proj}D)
  
  set(FFTW_SB_BUILD_FLOAT_DIR ${CMAKE_BINARY_DIR}/${proj}/src/${projFloat})
  set(FFTW_SB_BUILD_DOUBLE_DIR ${CMAKE_BINARY_DIR}/${proj}/src/${projDouble})
  
  if(MSVC)
    # TODO : get precompiled binaries as not all MSVC versions can compile FFTW
      message(STATUS "  FFTW SuperBuild is not available yet...")
      add_custom_target(${proj})
  else()
    message(STATUS "  Using FFTW SuperBuild version")
    # Compile the float version of FFTW
    ExternalProject_Add(${projFloat}
      PREFIX ${proj}
      URL "http://www.fftw.org/fftw-3.3.4.tar.gz"
      URL_MD5 2edab8c06b24feeb3b82bbb3ebf3e7b3
      SOURCE_DIR ${FFTW_SB_BUILD_FLOAT_DIR}
      INSTALL_DIR ${SB_INSTALL_PREFIX}
      DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
      CONFIGURE_COMMAND
        ${FFTW_SB_BUILD_FLOAT_DIR}/configure
            --prefix=${SB_INSTALL_PREFIX}
            --enable-shared
            --disable-static
            --enable-float
            --enable-threads
            --disable-fortran
      DEPENDS ${${proj}_DEPENDENCIES}
      )
      
    #ExternalProject_Add_Step(${projFloat} copy_source
    #  COMMAND ${CMAKE_COMMAND} -E copy_directory 
    #    ${FFTW_SB_SRC} ${FFTW_SB_BUILD_FLOAT_DIR}
    #  DEPENDEES patch update
    #  DEPENDERS configure
    #  )
    
    # Compile the double version of FFTW
    ExternalProject_Add(${proj}
      PREFIX ${proj}
      URL "http://www.fftw.org/fftw-3.3.4.tar.gz"
      URL_MD5 2edab8c06b24feeb3b82bbb3ebf3e7b3
      SOURCE_DIR ${FFTW_SB_BUILD_DOUBLE_DIR}
      INSTALL_DIR ${SB_INSTALL_PREFIX}
      DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
      CONFIGURE_COMMAND
        ${FFTW_SB_BUILD_DOUBLE_DIR}/configure
            --prefix=${SB_INSTALL_PREFIX}
            --enable-shared
            --disable-static
            --disable-float
            --enable-threads
            --disable-fortran
      DEPENDS ${${proj}_DEPENDENCIES}
      )
      
    #ExternalProject_Add_Step(${projDouble} copy_source
    #  COMMAND ${CMAKE_COMMAND} -E copy_directory 
    #    ${FFTW_SB_SRC} ${FFTW_SB_BUILD_DOUBLE_DIR}
    #  DEPENDEES patch update
    #  DEPENDERS configure
    #  )
    
    add_dependencies(${proj} ${projFloat})
    
    set(_SB_${proj}_INCLUDE_PATH ${SB_INSTALL_PREFIX}/include)
    
  endif()
  


endif()
endif()
