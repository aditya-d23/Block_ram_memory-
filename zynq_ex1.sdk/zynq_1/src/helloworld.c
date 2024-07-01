/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */
#include "amit1.h"

#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xgpio.h"
#include"xil_io.h"
#include "xbram.h"
#include <time.h>
#include <unistd.h>
#include<stdint.h>

#define LED_CHANNEL 1
#define SWITCH_CHANNEL 2
#define LED 0xFF

#define SWITCH 0x00

int main()
{XGpio Gpio; /* The Instance of the GPIO Driver */

XBram Bram0, Bram1, Bram2,Bram3, Bram4,Bram5, Bram6,Bram7, Bram8;	/* The Instance of the BRAM Driver */

XBram_Config *ConfigPtr0,*ConfigPtr1,*ConfigPtr2,*ConfigPtr3,*ConfigPtr4,*ConfigPtr5,*ConfigPtr6,*ConfigPtr7,*ConfigPtr8;

u32  Status,Status0,Status1,Status2,Status3,Status4,Status5,Status6,Status7,Status8;




ConfigPtr0 = XBram_LookupConfig(XPAR_BRAM_0_DEVICE_ID);
	if (ConfigPtr0 == (XBram_Config *) NULL) {
		return XST_FAILURE;
	}

	Status0 = XBram_CfgInitialize(&Bram0, ConfigPtr0,
				     ConfigPtr0->CtrlBaseAddress);
	if (Status0 != XST_SUCCESS) {
		return XST_FAILURE;
	}


ConfigPtr1 = XBram_LookupConfig(XPAR_BRAM_1_DEVICE_ID);
	if (ConfigPtr1 == (XBram_Config *) NULL) {
		return XST_FAILURE;
	}

	Status1 = XBram_CfgInitialize(&Bram1, ConfigPtr1,
				     ConfigPtr1->CtrlBaseAddress);
	if (Status1 != XST_SUCCESS) {
		return XST_FAILURE;
	}


	ConfigPtr2 = XBram_LookupConfig(XPAR_BRAM_2_DEVICE_ID);
		if (ConfigPtr2 == (XBram_Config *) NULL) {
			return XST_FAILURE;
		}

		Status2 = XBram_CfgInitialize(&Bram2, ConfigPtr2,
					     ConfigPtr2->CtrlBaseAddress);
		if (Status2 != XST_SUCCESS) {
			return XST_FAILURE;
		}






	ConfigPtr3 = XBram_LookupConfig(XPAR_BRAM_3_DEVICE_ID);
		if (ConfigPtr3 == (XBram_Config *) NULL) {
			return XST_FAILURE;
		}

		Status3 = XBram_CfgInitialize(&Bram3, ConfigPtr3,
				ConfigPtr3->CtrlBaseAddress);
		if (Status3 != XST_SUCCESS) {
			return XST_FAILURE;
		}

		ConfigPtr4 = XBram_LookupConfig(XPAR_BRAM_4_DEVICE_ID);
			if (ConfigPtr4 == (XBram_Config *) NULL) {
				return XST_FAILURE;
			}

			Status4 = XBram_CfgInitialize(&Bram4, ConfigPtr4,
					ConfigPtr4->CtrlBaseAddress);
			if (Status4 != XST_SUCCESS) {
				return XST_FAILURE;
			}


			ConfigPtr5 = XBram_LookupConfig(XPAR_BRAM_5_DEVICE_ID);
				if (ConfigPtr5 == (XBram_Config *) NULL) {
					return XST_FAILURE;
				}

				Status5 = XBram_CfgInitialize(&Bram5, ConfigPtr5,
						ConfigPtr5->CtrlBaseAddress);
				if (Status5 != XST_SUCCESS) {
					return XST_FAILURE;
				}





	ConfigPtr6 = XBram_LookupConfig(XPAR_BRAM_6_DEVICE_ID);
	if (ConfigPtr6 == (XBram_Config *) NULL) {
		return XST_FAILURE;
	}

	Status6 = XBram_CfgInitialize(&Bram6, ConfigPtr6,
			ConfigPtr6->CtrlBaseAddress);
	if (Status6 != XST_SUCCESS) {
		return XST_FAILURE;
	}


	ConfigPtr7 = XBram_LookupConfig(XPAR_BRAM_7_DEVICE_ID);
		if (ConfigPtr7 == (XBram_Config *) NULL) {
			return XST_FAILURE;
		}

		Status7 = XBram_CfgInitialize(&Bram7, ConfigPtr7,
				ConfigPtr7->CtrlBaseAddress);
		if (Status7 != XST_SUCCESS) {
			return XST_FAILURE;
		}

		ConfigPtr8 = XBram_LookupConfig(XPAR_BRAM_8_DEVICE_ID);
			if (ConfigPtr8 == (XBram_Config *) NULL) {
				return XST_FAILURE;
			}

			Status8 = XBram_CfgInitialize(&Bram8, ConfigPtr8,
					ConfigPtr8->CtrlBaseAddress);
			if (Status8 != XST_SUCCESS) {
				return XST_FAILURE;
			}

  u32 j[5],j1[5];
 u32  outdata,outdata1,sum=0;

	volatile int Delay;
/* Initialize the GPIO driver */
	Status = XGpio_Initialize(&Gpio, XPAR_GPIO_0_BASEADDR);
	if (Status != XST_SUCCESS) {
		xil_printf("Gpio Initialization Failed\r\n");
		return XST_FAILURE;
	}

	/* writing to the bram */
	/*for(int k=0 ;k<5;k++)
	{  xil_printf("Enter no %d: \n\r",k+1);
	scanf("%d",&j[k]);
	 xil_printf("the number  is :%d  \n\r",j[k]);} */

	int i0=0,i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,i7=0,i8=0;

	/*    for( int k=0;k<450;k++)
	    {

	    // Fetch the least significant 4 bits using bitwise AND with 0xF (binary 00001111)
	    unsigned int lsb4 = image_data[k] & 0x0000000F;

	    // Print the result
	    //printf("The 32b bit number is: 0x%X\n", image_data[k]);


	    switch (lsb4) {
	        case 0:
	           XBram_WriteReg(XPAR_BRAM_0_DEVICE_ID, i0, image_data[k]);
	           i0=i0+4;
	            break;
	        case 1:
	           XBram_WriteReg(XPAR_BRAM_1_DEVICE_ID, i1, image_data[k]);
	           i1=i1+4;
	            break;
	        case 2:
	           XBram_WriteReg(XPAR_BRAM_2_DEVICE_ID, i2, image_data[k]);
	           i2=i2+4;
	        break;
	        case 3:
	            XBram_WriteReg(XPAR_BRAM_3_DEVICE_ID, i3, image_data[k]);
	           i3=i3+4;
	            break;
	        case 4:
	            XBram_WriteReg(XPAR_BRAM_4_DEVICE_ID, i4, image_data[k]);
	           i4=i4+4;
	            break;
	        case 5:
	            XBram_WriteReg(XPAR_BRAM_5_DEVICE_ID, i5, image_data[k]);
	           i5=i5+4;
	            break;
	        case 6:
	            XBram_WriteReg(XPAR_BRAM_6_DEVICE_ID, i6, image_data[k]);
	           i6=i6+4;
	            break;
	        case 7:
	            XBram_WriteReg(XPAR_BRAM_7_DEVICE_ID, i7, image_data[k]);
	           i7=i7+4;
	            break;
	        case 8:
	            XBram_WriteReg(XPAR_BRAM_8_DEVICE_ID, i8, image_data[k]);
	           i8=i8+4;
	        break;




	    }

	    } */


for( int k=0,i=0;k<450;k++)
		{unsigned int lsb4 = image_data[k] & 0x0000000F;
		if(lsb4==2)
		{ XBram_WriteReg(XPAR_BRAM_2_DEVICE_ID, i, image_data[k]);
		i=i+4;}
		}

	 for(int j=0;j<250;j=j+4)
		       { XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, j);
		       xil_printf("  data from bram2  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, j));
		      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
		       }




	for( int k=0,i=0;k<450;k++)
		{unsigned int lsb4 = image_data[k] & 0x0000000F;
		if(lsb4==1)
		{ XBram_WriteReg(XPAR_BRAM_1_DEVICE_ID, i, image_data[k]);
		i=i+4;}
		}

	 for(int j=0;j<250;j=j+4)
			     	       { XBram_ReadReg(XPAR_BRAM_1_DEVICE_ID, j);
			     	       xil_printf("  data from bram1  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_1_DEVICE_ID, j));
			     	      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
			     	       }

	for( int k=0,i=0;k<450;k++)
			{unsigned int lsb4 = image_data[k] & 0x0000000F;
			if(lsb4==0)
			{ XBram_WriteReg(XPAR_BRAM_0_DEVICE_ID, i, image_data[k]);
			i=i+4;}
			}


		/* reading from the bram*/




	      // sum=sum + XBram_ReadReg(XPAR_BRAM_0_DEVICE_ID, i);}
	 for(int j=0;j<250;j=j+4)
	 { XBram_ReadReg(XPAR_BRAM_0_DEVICE_ID, j);
	     	       xil_printf("  data from bram0  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_0_DEVICE_ID, j));
	     	      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
	     	       }

	 for( int k=0,i=0;k<450;k++)
	 	{unsigned int lsb4 = image_data[k] & 0x0000000F;
	 	if(lsb4==3)
	 	{ XBram_WriteReg(XPAR_BRAM_3_DEVICE_ID, i, image_data[k]);
	 	i=i+4;}
	 	}

	 	 for(int j=0;j<250;j=j+4)
	 		       { XBram_ReadReg(XPAR_BRAM_3_DEVICE_ID, j);
	 		       xil_printf("  data from bram3  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_3_DEVICE_ID, j));
	 		      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
	 		       }




	 	for( int k=0,i=0;k<450;k++)
	 		{unsigned int lsb4 = image_data[k] & 0x0000000F;
	 		if(lsb4==4)
	 		{ XBram_WriteReg(XPAR_BRAM_4_DEVICE_ID, i, image_data[k]);
	 		i=i+4;}
	 		}

	 	 for(int j=0;j<250;j=j+4)
	 			     	       { XBram_ReadReg(XPAR_BRAM_4_DEVICE_ID, j);
	 			     	       xil_printf("  data from bram4  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_4_DEVICE_ID, j));
	 			     	      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
	 			     	       }

	 	for( int k=0,i=0;k<450;k++)
	 			{unsigned int lsb4 = image_data[k] & 0x0000000F;
	 			if(lsb4==5)
	 			{ XBram_WriteReg(XPAR_BRAM_5_DEVICE_ID, i, image_data[k]);
	 			i=i+4;}
	 			}


	 		/* reading from the bram*/




	 	      // sum=sum + XBram_ReadReg(XPAR_BRAM_0_DEVICE_ID, i);}
	 	 for(int j=0;j<250;j=j+4)
	 	 { XBram_ReadReg(XPAR_BRAM_5_DEVICE_ID, j);
	 	     	       xil_printf("  data from bram5  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_5_DEVICE_ID, j));
	 	     	      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
	 	     	       }

	 	for( int k=0,i=0;k<450;k++)
	 		{unsigned int lsb4 = image_data[k] & 0x0000000F;
	 		if(lsb4==6)
	 		{ XBram_WriteReg(XPAR_BRAM_6_DEVICE_ID, i, image_data[k]);
	 		i=i+4;}
	 		}

	 		 for(int j=0;j<250;j=j+4)
	 			       { XBram_ReadReg(XPAR_BRAM_6_DEVICE_ID, j);
	 			       xil_printf("  data from bram6  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_6_DEVICE_ID, j));
	 			      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
	 			       }




	 		for( int k=0,i=0;k<450;k++)
	 			{unsigned int lsb4 = image_data[k] & 0x0000000F;
	 			if(lsb4==7)
	 			{ XBram_WriteReg(XPAR_BRAM_7_DEVICE_ID, i, image_data[k]);
	 			i=i+4;}
	 			}

	 		 for(int j=0;j<250;j=j+4)
	 				     	       { XBram_ReadReg(XPAR_BRAM_7_DEVICE_ID, j);
	 				     	       xil_printf("  data from bram7  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_7_DEVICE_ID, j));
	 				     	      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
	 				     	       }

	 		for( int k=0,i=0;k<450;k++)
	 				{unsigned int lsb4 = image_data[k] & 0x0000000F;
	 				if(lsb4==8)
	 				{ XBram_WriteReg(XPAR_BRAM_8_DEVICE_ID, i, image_data[k]);
	 				i=i+4;}
	 				}


	 			/* reading from the bram*/




	 		      // sum=sum + XBram_ReadReg(XPAR_BRAM_0_DEVICE_ID, i);}
	 		 for(int j=0;j<250;j=j+4)
	 		 { XBram_ReadReg(XPAR_BRAM_8_DEVICE_ID, j);
	 		     	       xil_printf("  data from bram8  offset addres %d  is  : 0x%X \n\r",j ,XBram_ReadReg(XPAR_BRAM_8_DEVICE_ID, j));
	 		     	      // XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_2_DEVICE_ID, i));
	 		     	       }


	     /*writing start */
	/*  XBram_WriteReg(XPAR_BRAM_1_DEVICE_ID, 0, sum);
	       		        /*writing over*/

	       /* reading from the bram1*/



	       	 /*      xil_printf(" sum of all the 5 numbers stored in bram2 is :   %d  \n\r" ,XBram_ReadReg(XPAR_BRAM_1_DEVICE_ID, 0));
	       	       XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, XBram_ReadReg(XPAR_BRAM_1_DEVICE_ID, 0));
	       	       sleep(3600);



	/* Set the direction for all signals as inputs except the LED output */
	/*	XGpio_SetDataDirection(&Gpio, SWITCH_CHANNEL, SWITCH);

    init_platform();



 /*  while(1)
    {  u32 switches = XGpio_DiscreteRead(&Gpio, SWITCH_CHANNEL);

    xil_printf("!checked switches %x\r\n",switches);
     Wait a small amount of time so the LED is visible */
    		 /*  for (Delay = 0; Delay < 20000000; Delay++);} */
         //sleep(1);}
  //  print("Hello World\n\r");

    cleanup_platform();
    return 0;
}
