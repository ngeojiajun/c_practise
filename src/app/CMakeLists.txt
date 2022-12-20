add_executable(app 
src/main.c
src/ui/ui.c 
include/ui/ui.h

src/game/interpreter.c 
src/game/utils.c 
src/game/definitions.c
include/game/definitions.h
include/game/interpreter.h 
include/game/utils.h 
include/game/types.h

src/game/actions/look.c 
src/game/actions/inventory.c 
src/game/actions/go.c 
src/game/actions/pick.c 
)
target_link_libraries(app stdlib)