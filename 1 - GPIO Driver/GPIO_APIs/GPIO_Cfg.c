#include "GPIO.h"
#include "GPIO_Cfg.h"

const GPIO_CfgType GPIO_ConfigParam [GPIO_GROUPS_NUMBER] =
		{
				{
						1,
						1<<0,
						0xff,
						0xff
				},
				{
						1,
						1<<1,
						0xff,
						0xff
			    },
			    {
					    3,
					    1<<1,
					    0x00,
					    0xff
			    },
			    {
					    3,
					    1<<3,
					    0x00,
					    0xff
			    }

		};
