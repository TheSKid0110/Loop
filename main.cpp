#include <GarrysMod/Lua/Interface.h>

using namespace GarrysMod::Lua;

LUA_FUNCTION(IterateTable)
{
    LUA->CheckType(1, Type::Table);
    LUA->CheckType(2, Type::Function);

    LUA->PushNil(); // First key
    while (LUA->Next(1) != 0)
    {
        // Stack now contains: -1 => value; -2 => key; -3 => table
        LUA->Push(2); // Push the callback function
        LUA->Push(-3); // Push the key
        LUA->Push(-3); // Push the value
        LUA->Call(2, 0); // Call the callback function with 2 arguments and 0 return values

        LUA->Pop(1); // Remove value, keep key for next iteration
    }

    return 0;
}

GMOD_MODULE_OPEN()
{
    LUA->PushSpecial(SPECIAL_GLOB); // Push the global table
    LUA->PushCFunction(IterateTable);
    LUA->SetField(-2, "IterateTable");
    LUA->Pop();

    return 0;
}

GMOD_MODULE_CLOSE()
{
    return 0;
}
