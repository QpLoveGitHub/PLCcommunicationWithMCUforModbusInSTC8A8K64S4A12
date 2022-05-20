#include "main.h"
#include "SystemManage.h"
#include "SystemState_Idle.h"
#include "SystemManageDef.h"

volatile int exit_code = 0;


int  main(void)
{
	SystemState_CurrentState_Set(SystemState_Idle);
	while (1)
    {
        SystemState_Manage();
    }

	for(;;)
    {
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}
