
target_sources( ${PROJECT_NAME}
	PRIVATE
	    ${CMAKE_CURRENT_LIST_DIR}/Block.h
		${CMAKE_CURRENT_LIST_DIR}/CutPursuit.h
		${CMAKE_CURRENT_LIST_DIR}/Graph.h
		${CMAKE_CURRENT_LIST_DIR}/MaxFlow.h
		${CMAKE_CURRENT_LIST_DIR}/OMPNumThreads.h
		${CMAKE_CURRENT_LIST_DIR}/Partition.h
)

target_include_directories( ${PROJECT_NAME}
	PUBLIC
	    ${CMAKE_CURRENT_LIST_DIR}
)