add_executable(app 
src/main.c
src/ui/ui.c 
include/ui/ui.h

src/game/interpreter.c 
src/game/definitions.c
include/game/definitions.h
include/game/interpreter.h 
include/game/types.h

src/game/actions/look.c 
)
target_link_libraries(app stdlib)