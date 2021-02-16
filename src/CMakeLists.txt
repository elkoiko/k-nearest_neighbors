set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES 
    main.cpp 
    Data.cpp Data.hpp 
    Sample.cpp Sample.hpp 
    Features.cpp Features.hpp 
    Knn.hpp Knn.cpp 
    KnnCosine.hpp KnnCosine.cpp 
    ClassificationReport.hpp ClassificationReport.cpp 
    StringUtils.cpp StringUtils.hpp
    KnnEuclidian.cpp KnnEuclidian.hpp
    )

add_executable(${BINARY} ${SOURCES})

add_compile_options(${BINARY} PUBLIC -Wall -O3)

add_library(${BINARY}_lib STATIC ${SOURCES})