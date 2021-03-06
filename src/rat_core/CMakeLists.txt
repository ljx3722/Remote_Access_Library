project(librat_core)

if(WIN32)
    set(REMOTE_ACCESS_PLATFORM_SRC     

    )

	set(REMOTE_ACCESS_PLATFORM_LIBS    
	
    )
	set(REMOTE_ACCESS_PLATFORM_INC     
        ../../include/windows
        ../src/windows
		
    )

elseif(APPLE)

    set(REMOTE_ACCESS_PLATFORM_SRC
  
    )
    set(REMOTE_ACCESS_PLATFORM_INC
        ../../include/ios
        ../src/ios
    )

else()
	set(REMOTE_ACCESS_PLATFORM_SRC
	
	)
  
	set(REMOTE_ACCESS_PLATFORM_INC
        ../../include/linux
        ../src/linux
		${X11_INCLUDE_DIR}
    )
	find_package(Threads REQUIRED)
	set(REMOTE_ACCESS_PLATFORM_LIBS
		${CMAKE_THREAD_LIBS_INIT}
	)

endif()

	

set(REMOTE_ACCESS_COMMON_SRC 	

	ClientDriver.cpp
	ServerDriver.cpp

	../../include/IClientDriver.h
	../../include/ClientDriver.h
	../../include/ServerDriver.h
	../../include/IServerDriver.h

	../../include/NetworkStructs.h
	../../include/Configs.h
	../../include/INetworkHandlers.h
	../../include/Logging.h
	../../include/Shapes.h
)
set(REMOTE_ACCESS_COMMON_INC
	${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)
find_package(libjpegturbo REQUIRED)
find_package(OpenSSL REQUIRED)

set(REMOTE_ACCESS_INCLUDE_DIRS 
	${REMOTE_ACCESS_COMMON_INC} 
	${REMOTE_ACCESS_PLATFORM_INC} 
	${OPENSSL_INCLUDE_DIR}
	${LIBJPEGTURBO_INCLUDE_DIRS}
	${SCREEN_CAPTURE_INCLUDE_DIRS}
	${WEBSOCKET_LITE_INCLUDE_DIRS}
	${CLIPBOARD_LITE_INCLUDE_DIRS}
	${INPUT_LITE_INCLUDE_DIRS}
	CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE
)

set(REMOTE_ACCESS_LIBS
	${PROJECT_NAME}
	${REMOTE_ACCESS_PLATFORM_LIBS} 
	${OPENSSL_LIBRARIES} 
	${LIBJPEGTURBO_LIBRARIES}
	${SCREEN_CAPTURE_LIB}
	${WEBSOCKET_LITE_LIBS}
	${CLIPBOARD_LITE_LIBS}
	${INPUT_LITE_LIBS}
	CACHE INTERNAL "${PROJECT_NAME}: Include Libraries" FORCE
)

include_directories(${REMOTE_ACCESS_INCLUDE_DIRS})
add_library(${PROJECT_NAME} ${REMOTE_ACCESS_COMMON_SRC} ${REMOTE_ACCESS_PLATFORM_SRC})

target_link_libraries(${REMOTE_ACCESS_LIBS})

