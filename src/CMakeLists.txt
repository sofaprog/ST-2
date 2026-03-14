# Только библиотека circle (удалила ST-2)
add_library(circle STATIC circle.cpp tasks.cpp)
target_include_directories(circle PUBLIC ../include)

add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info PUBLIC ../include)
target_link_libraries(${PROJECT_NAME}.info circle)

install(TARGETS circle
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(TARGETS ${PROJECT_NAME}.info
        RUNTIME DESTINATION bin)
install(FILES ../include/circle.h ../include/tasks.h DESTINATION include)