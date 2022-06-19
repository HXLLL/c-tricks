project(c_tricks C)

#macro
add_executable(base_2_representation macro/base_2_representation.c)
add_executable(coroutine macro/coroutine.c)
add_executable(generic_function macro/generic_function.c)
add_executable(generic_linked_list macro/generic_linked_list.c)
add_executable(indirect_stringify macro/indirect_stringify.c)

# misc
add_executable(duff_device misc/duff_device.c)
add_executable(statement_expression misc/statement_expression.c)
