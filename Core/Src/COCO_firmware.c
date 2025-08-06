/*
 * COCO_firmware.c
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


#include "COCO_firmware.h"


void UART_Buffer_init(Speed_Joint_Data *typedef_SJ_data , CAN_HandleTypeDef *can1 , CAN_HandleTypeDef *can2 ){
	               //버퍼 초기화 함수. 여기서 초기화 된 정보들로 로봇의 관절들이 기본 위치에 도달도록 할 것임

	typedef_SJ_data->index =0;

	typedef_SJ_data->pos_Left_Front_Hip_AA.fulldata = 0;
	typedef_SJ_data->pos_Left_Front_Hip_FE.fulldata = 0;
	typedef_SJ_data->pos_Left_Front_Knee.fulldata = 0;

	typedef_SJ_data->pos_Left_Rear_Hip_AA.fulldata = 0;
	typedef_SJ_data->pos_Left_Rear_Hip_FE.fulldata = 0;
	typedef_SJ_data->pos_Left_Rear_Knee.fulldata = 0;

	typedef_SJ_data->pos_Right_Front_Hip_AA.fulldata = 0;
	typedef_SJ_data->pos_Right_Front_Hip_FE.fulldata = 0;
	typedef_SJ_data->pos_Right_Front_Knee.fulldata = 0;

	typedef_SJ_data->pos_Right_Rear_Hip_AA.fulldata = 0;
	typedef_SJ_data->pos_Right_Rear_Hip_FE.fulldata = 0;
	typedef_SJ_data->pos_Right_Rear_Knee.fulldata = 0;

	typedef_SJ_data->speed_Right_Rear.fulldata = 0;
	typedef_SJ_data->speed_Right_Front.fulldata = 0;
	typedef_SJ_data->speed_Left_Rear.fulldata = 0;
	typedef_SJ_data->speed_Left_Front.fulldata = 0;

	for(int i=0; i<16; i++){
		typedef_SJ_data->uart_rxBuffer[i] = '\0';
	}



	 //cheak for your data payload !! //cheak for your data payload


	typedef_SJ_data->pos_Left_Front_Knee_Header.StdId = CAN_ID_LEFT_FRONT_KNEE|Set_Input_Pos;
	typedef_SJ_data->pos_Left_Front_Knee_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Left_Front_Knee_Header.DLC = 4;
	typedef_SJ_data->pos_Left_Front_Knee_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Left_Front_Hip_AA_Header.StdId = CAN_ID_LEFT_FRONT_HIP_AA|Set_Input_Pos;
	typedef_SJ_data->pos_Left_Front_Hip_AA_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Left_Front_Hip_AA_Header.DLC = 4;
	typedef_SJ_data->pos_Left_Front_Hip_AA_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Left_Front_Hip_FE_Header.StdId = CAN_ID_LEFT_FRONT_HIP_FE|Set_Input_Pos;
	typedef_SJ_data->pos_Left_Front_Hip_FE_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Left_Front_Hip_FE_Header.DLC = 4;
	typedef_SJ_data->pos_Left_Front_Hip_FE_Header.IDE = CAN_ID_STD;


	typedef_SJ_data->pos_Left_Rear_Knee_Header.StdId = CAN_ID_LEFT_REAR_KNEE|Set_Input_Pos;
	typedef_SJ_data->pos_Left_Rear_Knee_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Left_Rear_Knee_Header.DLC = 4;
	typedef_SJ_data->pos_Left_Rear_Knee_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Left_Rear_Hip_AA_Header.StdId = CAN_ID_LEFT_REAR_HIP_AA|Set_Input_Pos;
	typedef_SJ_data->pos_Left_Rear_Hip_AA_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Left_Rear_Hip_AA_Header.DLC = 4;
	typedef_SJ_data->pos_Left_Rear_Hip_AA_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Left_Rear_Hip_FE_Header.StdId = CAN_ID_LEFT_REAR_HIP_FE|Set_Input_Pos;
	typedef_SJ_data->pos_Left_Rear_Hip_FE_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Left_Rear_Hip_FE_Header.DLC = 4;
	typedef_SJ_data->pos_Left_Rear_Hip_FE_Header.IDE = CAN_ID_STD;


	typedef_SJ_data->pos_Right_Front_Knee_Header.StdId = CAN_ID_RIGHT_FRONT_KNEE|Set_Input_Pos;
	typedef_SJ_data->pos_Right_Front_Knee_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Right_Front_Knee_Header.DLC = 4;
	typedef_SJ_data->pos_Right_Front_Knee_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Right_Front_Hip_AA_Header.StdId = CAN_ID_RIGHT_FRONT_HIP_AA|Set_Input_Pos;
	typedef_SJ_data->pos_Right_Front_Hip_AA_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Right_Front_Hip_AA_Header.DLC = 4;
	typedef_SJ_data->pos_Right_Front_Hip_AA_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Right_Front_Hip_FE_Header.StdId = CAN_ID_RIGHT_FRONT_HIP_FE|Set_Input_Pos;
	typedef_SJ_data->pos_Right_Front_Hip_FE_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Right_Front_Hip_FE_Header.DLC = 4;
	typedef_SJ_data->pos_Right_Front_Hip_FE_Header.IDE = CAN_ID_STD;


	typedef_SJ_data->pos_Right_Rear_Knee_Header.StdId = CAN_ID_RIGHT_REAR_KNEE|Set_Input_Pos;
	typedef_SJ_data->pos_Right_Rear_Knee_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Right_Rear_Knee_Header.DLC = 4;
	typedef_SJ_data->pos_Right_Rear_Knee_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Right_Rear_Hip_AA_Header.StdId = CAN_ID_RIGHT_REAR_HIP_AA|Set_Input_Pos;
	typedef_SJ_data->pos_Right_Rear_Hip_AA_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Right_Rear_Hip_AA_Header.DLC = 4;
	typedef_SJ_data->pos_Right_Rear_Hip_AA_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->pos_Right_Rear_Hip_FE_Header.StdId = CAN_ID_RIGHT_REAR_HIP_FE|Set_Input_Pos;
	typedef_SJ_data->pos_Right_Rear_Hip_FE_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->pos_Right_Rear_Hip_FE_Header.DLC = 4;
	typedef_SJ_data->pos_Right_Rear_Hip_FE_Header.IDE = CAN_ID_STD;


	typedef_SJ_data->speed_Left_Front_Header.StdId = CAN_ID_LEFT_FRONT_WHEEL|Set_Input_Vel;
	typedef_SJ_data->speed_Left_Front_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->speed_Left_Front_Header.DLC = 4;
	typedef_SJ_data->speed_Left_Front_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->speed_Left_Rear_Header.StdId = CAN_ID_LEFT_REAR_WHEEL|Set_Input_Vel;
	typedef_SJ_data->speed_Left_Rear_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->speed_Left_Rear_Header.DLC = 4;
	typedef_SJ_data->speed_Left_Rear_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->speed_Right_Front_Header.StdId = CAN_ID_RIGHT_FRONT_WHEEL|Set_Input_Vel;
	typedef_SJ_data->speed_Right_Front_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->speed_Right_Front_Header.DLC = 4;
	typedef_SJ_data->speed_Right_Front_Header.IDE = CAN_ID_STD;

	typedef_SJ_data->speed_Right_Rear_Header.StdId = CAN_ID_RIGHT_REAR_WHEEL|Set_Input_Vel;
	typedef_SJ_data->speed_Right_Rear_Header.RTR = CAN_RTR_DATA;
	typedef_SJ_data->speed_Right_Rear_Header.DLC = 4;
	typedef_SJ_data->speed_Right_Rear_Header.IDE = CAN_ID_STD;


	typedef_SJ_data->hcan1 = *can1;
	typedef_SJ_data->hcan2 = *can2;                    // 이걸 포인터로 바꾸고 싶기는 한데 너무 귀찮은 작업임.... 의식의 흐름 기법이 이렇게 무섭습니다...
                                                       // 약간의 리소스 낭비는 그러려니 합시다 어쩔 수 없이

	typedef_SJ_data->CAN1_MailBox = 0;
	typedef_SJ_data->CAN2_MailBox = 0;

}



void Move_To_defalt_pos(Speed_Joint_Data *typedef_SJ_data ){
	//아무튼 초기 위치로 이동할 것인데 구조체를 받긴 함
	init_helper(typedef_SJ_data);

	Send_Data_CAN(typedef_SJ_data);

	HAL_Delay(2000); // 초기 위치로 이동하고 대기
}


uint16_t Send_CAN_Joint_Pos(Speed_Joint_Data *typedef_SJ_data, int joint_number){
	HAL_StatusTypeDef message_failed;

	switch(joint_number){
		case CAN_ID_LEFT_FRONT_KNEE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
					&typedef_SJ_data->pos_Left_Front_Knee_Header ,
					typedef_SJ_data->pos_Left_Front_Knee.data_8bit
					,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) 	return 1;

			break;

		case CAN_ID_LEFT_FRONT_HIP_AA:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
					&typedef_SJ_data->pos_Left_Front_Hip_AA_Header ,
					typedef_SJ_data->pos_Left_Front_Hip_AA.data_8bit
					,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1 <<1;

			break;

		case CAN_ID_LEFT_FRONT_HIP_FE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
					&typedef_SJ_data->pos_Left_Front_Hip_FE_Header ,
					typedef_SJ_data->pos_Left_Front_Hip_FE.data_8bit
					,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1<<2;

			break;

		case CAN_ID_RIGHT_FRONT_KNEE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
					&typedef_SJ_data->pos_Right_Front_Knee_Header ,
					typedef_SJ_data->pos_Right_Front_Knee.data_8bit
					,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1<<3;

			break;

		case CAN_ID_RIGHT_FRONT_HIP_AA:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
					&typedef_SJ_data->pos_Right_Front_Hip_AA_Header ,
					typedef_SJ_data->pos_Right_Front_Hip_AA.data_8bit
					,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1<<4;

			break;

		case CAN_ID_RIGHT_FRONT_HIP_FE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
					&typedef_SJ_data->pos_Right_Front_Hip_FE_Header ,
					typedef_SJ_data->pos_Right_Front_Hip_FE.data_8bit
					,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1<<5 ;

			break;


		case CAN_ID_LEFT_REAR_KNEE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
					&typedef_SJ_data->pos_Left_Rear_Knee_Header ,
					typedef_SJ_data->pos_Left_Rear_Knee.data_8bit
					,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<6;

			break;

		case CAN_ID_LEFT_REAR_HIP_AA:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
					&typedef_SJ_data->pos_Left_Rear_Hip_AA_Header ,
					typedef_SJ_data->pos_Left_Rear_Hip_AA.data_8bit
					,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<7;

			break;

		case CAN_ID_LEFT_REAR_HIP_FE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
					&typedef_SJ_data->pos_Left_Rear_Hip_FE_Header ,
					typedef_SJ_data->pos_Left_Rear_Hip_FE.data_8bit
					,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<8;

			break;

		case CAN_ID_RIGHT_REAR_KNEE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
					&typedef_SJ_data->pos_Right_Rear_Knee_Header ,
					typedef_SJ_data->pos_Right_Rear_Knee.data_8bit
					,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<9;

			break;

		case CAN_ID_RIGHT_REAR_HIP_AA:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
					&typedef_SJ_data->pos_Right_Rear_Hip_AA_Header ,
					typedef_SJ_data->pos_Right_Rear_Hip_AA.data_8bit
					,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<10;

			break;

		case CAN_ID_RIGHT_REAR_HIP_FE:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
					&typedef_SJ_data->pos_Right_Rear_Hip_FE_Header ,
					typedef_SJ_data->pos_Right_Rear_Hip_FE.data_8bit
					,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<11;

			break;

		default:
			return 1<<14;
	}

	return 0;
}


uint8_t Send_CAN_Wheel_Speed(Speed_Joint_Data *typedef_SJ_data , int wheel_number){

	HAL_StatusTypeDef message_failed;

	switch(wheel_number){
		case CAN_ID_LEFT_FRONT_WHEEL:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
								&typedef_SJ_data->speed_Left_Front_Header ,
								typedef_SJ_data->speed_Left_Front.data_8bit
								,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1 ;

			break;

		case CAN_ID_RIGHT_FRONT_WHEEL:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
								&typedef_SJ_data->speed_Right_Front_Header ,
								typedef_SJ_data->speed_Right_Front.data_8bit
								,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1<<1;

			break;

		case CAN_ID_LEFT_REAR_WHEEL:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
								&typedef_SJ_data->speed_Left_Rear_Header ,
								typedef_SJ_data->speed_Left_Rear.data_8bit
								,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<2;

			break;

		case CAN_ID_RIGHT_REAR_WHEEL:
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
								&typedef_SJ_data->speed_Right_Rear_Header ,
								typedef_SJ_data->speed_Right_Rear.data_8bit
								,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<3;

			break;

		default:
			return 1<<6;
	}

	return 0;
}



// using a user - defined position or speed
int16_t ReWrite_Send_CAN_Joint_Pos(Speed_Joint_Data *typedef_SJ_data , int joint_number ,float *position){

	HAL_StatusTypeDef message_failed;

	switch(joint_number){
			case CAN_ID_LEFT_FRONT_KNEE:
				typedef_SJ_data->pos_Left_Front_Knee.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
						&typedef_SJ_data->pos_Left_Front_Knee_Header ,
						typedef_SJ_data->pos_Left_Front_Knee.data_8bit
						,&typedef_SJ_data->CAN1_MailBox);
				if(message_failed != HAL_OK) return 1 ;


				break;

			case CAN_ID_LEFT_FRONT_HIP_AA:
				typedef_SJ_data->pos_Left_Front_Hip_AA.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
						&typedef_SJ_data->pos_Left_Front_Hip_AA_Header ,
						typedef_SJ_data->pos_Left_Front_Hip_AA.data_8bit
						,&typedef_SJ_data->CAN1_MailBox);
				if(message_failed != HAL_OK) return 1 <<1;

				break;

			case CAN_ID_LEFT_FRONT_HIP_FE:
				typedef_SJ_data->pos_Left_Front_Hip_FE.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
						&typedef_SJ_data->pos_Left_Front_Hip_FE_Header ,
						typedef_SJ_data->pos_Left_Front_Hip_FE.data_8bit
						,&typedef_SJ_data->CAN1_MailBox);
				if(message_failed != HAL_OK) return 1<<2;

				break;

			case CAN_ID_RIGHT_FRONT_KNEE:
				typedef_SJ_data->pos_Right_Front_Knee.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
						&typedef_SJ_data->pos_Right_Front_Knee_Header ,
						typedef_SJ_data->pos_Right_Front_Knee.data_8bit
						,&typedef_SJ_data->CAN1_MailBox);
				if(message_failed != HAL_OK) return 1<<3 ;

				break;

			case CAN_ID_RIGHT_FRONT_HIP_AA:
				typedef_SJ_data->pos_Right_Front_Hip_AA.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
						&typedef_SJ_data->pos_Right_Front_Hip_AA_Header ,
						typedef_SJ_data->pos_Right_Front_Hip_AA.data_8bit
						,&typedef_SJ_data->CAN1_MailBox);
				if(message_failed != HAL_OK) return 1<<4;

				break;

			case CAN_ID_RIGHT_FRONT_HIP_FE:
				typedef_SJ_data->pos_Right_Front_Hip_FE.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
						&typedef_SJ_data->pos_Right_Front_Hip_FE_Header ,
						typedef_SJ_data->pos_Right_Front_Hip_FE.data_8bit
						,&typedef_SJ_data->CAN1_MailBox);
				if(message_failed != HAL_OK) return 1<<5;

				break;


			case CAN_ID_LEFT_REAR_KNEE:
				typedef_SJ_data->pos_Left_Rear_Knee.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
						&typedef_SJ_data->pos_Left_Rear_Knee_Header ,
						typedef_SJ_data->pos_Left_Rear_Knee.data_8bit
						,&typedef_SJ_data->CAN2_MailBox);
				if(message_failed != HAL_OK) return 1<<6;

				break;

			case CAN_ID_LEFT_REAR_HIP_AA:
				typedef_SJ_data->pos_Left_Rear_Hip_AA.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
						&typedef_SJ_data->pos_Left_Rear_Hip_AA_Header ,
						typedef_SJ_data->pos_Left_Rear_Hip_AA.data_8bit
						,&typedef_SJ_data->CAN2_MailBox);
				if(message_failed != HAL_OK) return 1<<7;

				break;

			case CAN_ID_LEFT_REAR_HIP_FE:
				typedef_SJ_data->pos_Left_Rear_Hip_FE.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
						&typedef_SJ_data->pos_Left_Rear_Hip_FE_Header ,
						typedef_SJ_data->pos_Left_Rear_Hip_FE.data_8bit
						,&typedef_SJ_data->CAN2_MailBox);
				if(message_failed != HAL_OK) return 1<<8;

				break;

			case CAN_ID_RIGHT_REAR_KNEE:
				typedef_SJ_data->pos_Right_Rear_Knee.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
						&typedef_SJ_data->pos_Right_Rear_Knee_Header ,
						typedef_SJ_data->pos_Right_Rear_Knee.data_8bit
						,&typedef_SJ_data->CAN2_MailBox);
				if(message_failed != HAL_OK) return 1<<9;

				break;

			case CAN_ID_RIGHT_REAR_HIP_AA:
				typedef_SJ_data->pos_Right_Rear_Hip_AA.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
						&typedef_SJ_data->pos_Right_Rear_Hip_AA_Header ,
						typedef_SJ_data->pos_Right_Rear_Hip_AA.data_8bit
						,&typedef_SJ_data->CAN2_MailBox);
				if(message_failed != HAL_OK) return 1<<10;

				break;

			case CAN_ID_RIGHT_REAR_HIP_FE:
				typedef_SJ_data->pos_Right_Rear_Hip_FE.joint_position = *position;
				message_failed=
				HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
						&typedef_SJ_data->pos_Right_Rear_Hip_FE_Header ,
						typedef_SJ_data->pos_Right_Rear_Hip_FE.data_8bit
						,&typedef_SJ_data->CAN2_MailBox);
				if(message_failed != HAL_OK) return 1<<11;

				break;

			default:
				return 0x01<<14;
		}


	return 0;
}



uint8_t ReWrite_Send_CAN_Wheel_Speed(Speed_Joint_Data *typedef_SJ_data , int wheel_number ,float *speed){

	HAL_StatusTypeDef message_failed;

	switch(wheel_number){
		case CAN_ID_LEFT_FRONT_WHEEL:
			typedef_SJ_data->speed_Left_Front.wheel_speed[0] = *speed;
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
								&typedef_SJ_data->speed_Left_Front_Header ,
								typedef_SJ_data->speed_Left_Front.data_8bit
								,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1;

			break;

		case CAN_ID_RIGHT_FRONT_WHEEL:
			typedef_SJ_data->speed_Right_Front.wheel_speed[0] = *speed;
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1 ,
								&typedef_SJ_data->speed_Right_Front_Header ,
								typedef_SJ_data->speed_Right_Front.data_8bit
								,&typedef_SJ_data->CAN1_MailBox);
			if(message_failed != HAL_OK) return 1<<1;

			break;

		case CAN_ID_LEFT_REAR_WHEEL:
			typedef_SJ_data->speed_Left_Rear.wheel_speed[0] = *speed;
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
								&typedef_SJ_data->speed_Left_Rear_Header ,
								typedef_SJ_data->speed_Left_Rear.data_8bit
								,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<2;

			break;

		case CAN_ID_RIGHT_REAR_WHEEL:
			typedef_SJ_data->speed_Right_Rear.wheel_speed[0] = *speed;
			message_failed=
			HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2 ,
								&typedef_SJ_data->speed_Right_Rear_Header ,
								typedef_SJ_data->speed_Right_Rear.data_8bit
								,&typedef_SJ_data->CAN2_MailBox);
			if(message_failed != HAL_OK) return 1<<3;

			break;

		default:
			return 1<<6;
	}

	return 0;
}


void Send_Data_CAN(Speed_Joint_Data *typedef_SJ_data){

	uint16_t joint_failer_handler = 0 ;
	uint8_t speed_failer_handler = 0 ;

	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_LEFT_FRONT_KNEE);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_LEFT_FRONT_HIP_AA);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_LEFT_FRONT_HIP_FE);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_LEFT_REAR_KNEE);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_LEFT_REAR_HIP_AA);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_LEFT_REAR_HIP_FE);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_RIGHT_FRONT_KNEE);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_RIGHT_FRONT_HIP_AA);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_RIGHT_FRONT_HIP_FE);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_RIGHT_REAR_KNEE);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_RIGHT_REAR_HIP_AA);
	joint_failer_handler |= Send_CAN_Joint_Pos(typedef_SJ_data, CAN_ID_RIGHT_REAR_HIP_FE);

	speed_failer_handler |= Send_CAN_Wheel_Speed(typedef_SJ_data, CAN_ID_LEFT_FRONT_WHEEL);
    speed_failer_handler |= Send_CAN_Wheel_Speed(typedef_SJ_data, CAN_ID_LEFT_REAR_WHEEL);
	speed_failer_handler |= Send_CAN_Wheel_Speed(typedef_SJ_data, CAN_ID_RIGHT_FRONT_WHEEL);
	speed_failer_handler |= Send_CAN_Wheel_Speed(typedef_SJ_data, CAN_ID_RIGHT_REAR_WHEEL);

	if(joint_failer_handler){

		for(uint8_t i=0; i<12; i++){
			((joint_failer_handler && 1<<i)>>i) ? Send_CAN_Joint_Pos(typedef_SJ_data, (0x0A+i)<<5) : 0 ;
		}
	}

	if(speed_failer_handler){
		for(uint8_t i=0; i<12; i++){
			((speed_failer_handler && 1<<i)>>i) ? Send_CAN_Wheel_Speed(typedef_SJ_data, (0x16+i)<<5) : 0 ;
		}
	}

}

//아 여기 밑에는 부끄러우니까 안 봐줬으면..;;


void init_helper(Speed_Joint_Data *typedef_SJ_data){
	 CAN_TxHeaderTypeDef init_handler;

	    Reqest_state_init_buffer requestmode;
	    requestmode.commandsize = 8;               // 이 부분도 매크로 처리하거나 하자 << 그리고 변수이름도 잘못지음 걍 커맨드임 사이즈같은거 아님

	    init_handler.IDE = CAN_ID_STD;
	    init_handler.RTR = CAN_RTR_DATA;
	    init_handler.DLC =4;

	    //개노가다 오반데;;; 반복문 쓰고싶다...
	    init_handler.StdId = CAN_ID_LEFT_FRONT_KNEE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	    		             , &init_handler, requestmode.data_8bit
							 , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_LEFT_FRONT_HIP_AA|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	        		          , &init_handler, requestmode.data_8bit
	    					  , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_LEFT_FRONT_HIP_FE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	            		      , &init_handler, requestmode.data_8bit
	        				  , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_KNEE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                		  , &init_handler, requestmode.data_8bit
	            			  , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_HIP_AA|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                          , &init_handler, requestmode.data_8bit
	                		  , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_HIP_FE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                    	  , &init_handler, requestmode.data_8bit
	                		  , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_LEFT_FRONT_WHEEL|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                          , &init_handler, requestmode.data_8bit
	                    	  , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_WHEEL|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                		  , &init_handler, requestmode.data_8bit
	            			  , &typedef_SJ_data->CAN1_MailBox); HAL_Delay(1);

	    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	    init_handler.StdId = CAN_ID_LEFT_REAR_KNEE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	    		             , &init_handler, requestmode.data_8bit
							 , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_LEFT_REAR_HIP_AA|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	        		          , &init_handler, requestmode.data_8bit
	    					  , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_LEFT_REAR_HIP_FE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	            		      , &init_handler, requestmode.data_8bit
	        				  , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_KNEE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                		  , &init_handler, requestmode.data_8bit
	            			  , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_HIP_AA|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                          , &init_handler, requestmode.data_8bit
	                		  , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_HIP_FE|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                    	  , &init_handler, requestmode.data_8bit
	                		  , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_LEFT_REAR_WHEEL|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                          , &init_handler, requestmode.data_8bit
	                    	  , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_WHEEL|Set_Axis_Requested_State;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                		  , &init_handler, requestmode.data_8bit
	            			  , &typedef_SJ_data->CAN2_MailBox); HAL_Delay(1);

	                                                                       //앞으로는 이렇게 살지 말자...

	    Controller_mode_init_buffer controlmode;
	    controlmode.data_32bit[0] = 3;
	    controlmode.data_32bit[1] = 2;


	    init_handler.IDE = CAN_ID_STD;
	    init_handler.RTR = CAN_RTR_DATA;
	    init_handler.DLC =8;


	    init_handler.StdId = CAN_ID_LEFT_FRONT_KNEE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	    		             , &init_handler, controlmode.data_8bit
							 , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_LEFT_FRONT_HIP_AA|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	        		          , &init_handler, controlmode.data_8bit
	    					  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_LEFT_FRONT_HIP_FE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	            		      , &init_handler, controlmode.data_8bit
	        				  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_KNEE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                		  , &init_handler, controlmode.data_8bit
	            			  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_HIP_AA|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                          , &init_handler, controlmode.data_8bit
	                		  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_HIP_FE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                    	  , &init_handler, controlmode.data_8bit
	                		  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_LEFT_FRONT_WHEEL|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                          , &init_handler, controlmode.data_8bit
	                    	  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_FRONT_WHEEL|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan1
	                		  , &init_handler, controlmode.data_8bit
	            			  , &typedef_SJ_data->CAN1_MailBox);

	    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	    init_handler.StdId = CAN_ID_LEFT_REAR_KNEE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	    		             , &init_handler, controlmode.data_8bit
							 , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_LEFT_REAR_HIP_AA|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	        		          , &init_handler, controlmode.data_8bit
	    					  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_LEFT_REAR_HIP_FE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	            		      , &init_handler, controlmode.data_8bit
	        				  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_KNEE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                		  , &init_handler, controlmode.data_8bit
	            			  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_HIP_AA|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                          , &init_handler, controlmode.data_8bit
	                		  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_HIP_FE|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                    	  , &init_handler, controlmode.data_8bit
	                		  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_LEFT_REAR_WHEEL|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                          , &init_handler, controlmode.data_8bit
	                    	  , &typedef_SJ_data->CAN1_MailBox);

	    init_handler.StdId = CAN_ID_RIGHT_REAR_WHEEL|Set_Controller_Modes;
	    HAL_CAN_AddTxMessage(&typedef_SJ_data->hcan2
	                		  , &init_handler, controlmode.data_8bit
	            			  , &typedef_SJ_data->CAN1_MailBox);
}

