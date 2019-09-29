
set(WEB_SOCKETS_DIR ${PROJECT_ROOT}/arduinoWebSockets/src)
set(web_sockets_sources ${WEB_SOCKETS_DIR}/WebSocketsServer.cpp
                        ${WEB_SOCKETS_DIR}/WebSocketsClient.cpp
                        ${WEB_SOCKETS_DIR}/WebSockets.cpp
)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
)
add_subdirectory(targets/12e)