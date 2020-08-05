function(add_example name)
    add_executable(${name}
        ${name}/main.c
    )
    target_link_libraries(${name} zalg)
endfunction()

add_example(list)
add_example(dynamic_array)
