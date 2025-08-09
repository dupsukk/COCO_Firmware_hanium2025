/*
 * COCO_firmware.h
 *
 *  Created on: Aug 4, 2025
 *      Author: yoont
 */

/*
*************************************************************************************************
*                               PROJECT COCOWORKER 2025                                         *
*       Developoed by                                                                           *
*                Kim Sung Su                                                                    *
*                Kim Seung Yoon                                                                 *
*                Kim Se Rin                                                                     *
*                Kim Tae Yeon                                                                   *
*                                                                                               *
*       GitHub : https://github.com/taeyeon0909/hanium                                          *
*                                                                                               *
*       Suported by Hanium                                                                      *
*       Licensed under the MIT License                                                          *
*                                                                                               *
*       Copyright (c) TEAM COCOWORKER                                                           *
*                                                                                               *
*       This code is for the Hanium competition.                                                *
*                                                                                               *
*       FACT: Seoultech is the best school in the world                                         *
*                                                                                               *
*                                                                           2025.07.19          *
*************************************************************************************************
*/

#ifndef INC_COCO_FIRMWARE_H_
#define INC_COCO_FIRMWARE_H_

#include "main.h"



//command lists
#define CANOpen_NMT_Message 0x000
#define ODrive_Heartbeat_Message 0x001
#define ODrive_Estop_Message 0x002
//#define Get_Motor_Error 0x003
//#define Get_Encoder_Error* 0x004
//#define Get Sensorless Error* 0x005   //주석처리 된 부분은 공식 프로토콜이긴 하나 마스터가 센더가 아님
#define Set_Axis_Node_ID 0x006
#define Set_Axis_Requested_State 0x007
#define Set_Axis_Startup_Config 0x008
//#define Get_Encoder_Estimates* 0x009
//#define Get_Encoder_Count* 0x00A
#define Set_Controller_Modes 0x00B
#define Set_Input_Pos 0x00C
#define Set_Input_Vel 0x00D
#define Set_Input_Torque 0x00E
#define Set_Limits 0x00F
#define Start_Anticogging 0x010
#define Set_Traj_Vel_Limit 0x011
#define Set_Traj_Accel_Limits 0x012
#define Set_Traj_Inertia 0x013
//#define Get IQ* 0x014
//#define Get Sensorless Estimates* 0x015
#define Reboot_ODrive 0x016
#define Get_Vbus_Voltage 0x017
#define Clear_Errors 0x018
#define Set_Linear_Count 0x019
#define Set_Position_Gain 0x01A
#define Set_Vel_Gains 0x01B
//#define CANOpen_Heartbeat_Message** 0x700

//define CAN node id
#define CAN_ID_LEFT_FRONT_KNEE 0x0A << 5
#define CAN_ID_LEFT_FRONT_HIP_AA 0x0B << 5
#define CAN_ID_LEFT_FRONT_HIP_FE 0x0C << 5

#define CAN_ID_LEFT_REAR_KNEE 0x0D << 5
#define CAN_ID_LEFT_REAR_HIP_AA 0x0E << 5
#define CAN_ID_LEFT_REAR_HIP_FE 0x0F << 5

#define CAN_ID_RIGHT_FRONT_KNEE 0x10 << 5
#define CAN_ID_RIGHT_FRONT_HIP_AA 0x11 << 5
#define CAN_ID_RIGHT_FRONT_HIP_FE 0x12 << 5

#define CAN_ID_RIGHT_REAR_KNEE 0x13 << 5
#define CAN_ID_RIGHT_REAR_HIP_AA 0x14 << 5
#define CAN_ID_RIGHT_REAR_HIP_FE 0x15 << 5

#define CAN_ID_LEFT_FRONT_WHEEL 0x16 << 5
#define CAN_ID_LEFT_REAR_WHEEL 0x17 << 5
#define CAN_ID_RIGHT_FRONT_WHEEL 0x18 << 5
#define CAN_ID_RIGHT_REAR_WHEEL 0x19 << 5

//for your message, use bitwise or and bitshifts.




typedef union{
	uint64_t commandsize;
	uint32_t data_32bit[2];
	uint8_t data_8bit[8];
}Controller_mode_init_buffer;



typedef union{
	uint64_t fulldata;
	uint32_t commandsize;
	uint8_t data_8bit[4];
}Reqest_state_init_buffer;






typedef union{
	uint64_t fulldata;
	float joint_position;
	int16_t additional_command[4];
	uint8_t data_8bit[8];
}Posion_handler;




typedef union{
	uint64_t fulldata;
	float wheel_speed[2];
	uint8_t data_8bit[8];
}Speed_handler;



//typedef enum {false, true} bool ;




typedef struct{                         //as you can see this struct is for joint, wheel speed variable

	CAN_TxHeaderTypeDef speed_Left_Front_Header;
	CAN_TxHeaderTypeDef speed_Left_Rear_Header;
    CAN_TxHeaderTypeDef speed_Right_Front_Header;
    CAN_TxHeaderTypeDef speed_Right_Rear_Header;

    CAN_TxHeaderTypeDef pos_Left_Front_Knee_Header;
    CAN_TxHeaderTypeDef pos_Left_Front_Hip_AA_Header;
    CAN_TxHeaderTypeDef pos_Left_Front_Hip_FE_Header;

    CAN_TxHeaderTypeDef pos_Left_Rear_Knee_Header;
	CAN_TxHeaderTypeDef pos_Left_Rear_Hip_AA_Header;
	CAN_TxHeaderTypeDef pos_Left_Rear_Hip_FE_Header;

	CAN_TxHeaderTypeDef pos_Right_Front_Knee_Header;
	CAN_TxHeaderTypeDef pos_Right_Front_Hip_AA_Header;
	CAN_TxHeaderTypeDef pos_Right_Front_Hip_FE_Header;

	CAN_TxHeaderTypeDef pos_Right_Rear_Knee_Header;
	CAN_TxHeaderTypeDef pos_Right_Rear_Hip_AA_Header;
	CAN_TxHeaderTypeDef pos_Right_Rear_Hip_FE_Header;


	Speed_handler speed_Left_Front;
	Speed_handler speed_Left_Rear;
	Speed_handler speed_Right_Front;
	Speed_handler speed_Right_Rear;

	Posion_handler pos_Left_Front_Knee;
	Posion_handler pos_Left_Front_Hip_AA;
	Posion_handler pos_Left_Front_Hip_FE;

	Posion_handler pos_Left_Rear_Knee;
	Posion_handler pos_Left_Rear_Hip_AA;
	Posion_handler pos_Left_Rear_Hip_FE;

	Posion_handler pos_Right_Front_Knee;
	Posion_handler pos_Right_Front_Hip_AA;
	Posion_handler pos_Right_Front_Hip_FE;

	Posion_handler pos_Right_Rear_Knee;
	Posion_handler pos_Right_Rear_Hip_AA;
	Posion_handler pos_Right_Rear_Hip_FE;


    uint8_t uart_rxBuffer[16];                       //이 부분 참 마음에 안 드네
	short index;

	CAN_HandleTypeDef hcan1;
	CAN_HandleTypeDef hcan2;


	uint32_t CAN1_MailBox;
	uint32_t CAN2_MailBox;


}Speed_Joint_Data;






void UART_Buffer_init(Speed_Joint_Data *typedef_SJ_data , CAN_HandleTypeDef *hcan1 , CAN_HandleTypeDef *hcan2 );

void Move_To_defalt_pos(Speed_Joint_Data *typedef_SJ_data);

void init_helper(Speed_Joint_Data *typedef_SJ_data);

uint16_t Send_CAN_Joint_Pos(Speed_Joint_Data *typedef_SJ_data , int joint_number);

uint8_t Send_CAN_Wheel_Speed(Speed_Joint_Data *typedef_SJ_data , int wheel_number);

int16_t ReWrite_Send_CAN_Joint_Pos(Speed_Joint_Data *typedef_SJ_data , int joint_number ,float *position);

uint8_t ReWrite_Send_CAN_Wheel_Speed(Speed_Joint_Data *typedef_SJ_data , int wheel_number ,float *speed);

void Send_Data_CAN(Speed_Joint_Data *typedef_SJ_data);

void Send_Reqest_state_init_Message_CAN(CAN_HandleTypeDef *hcan , uint16_t CAN_ID );

void Send_Controlmode_init_Message_CAN(CAN_HandleTypeDef *hcan , uint16_t CAN_ID);



#endif /* INC_COCO_FIRMWARE_H_ */
