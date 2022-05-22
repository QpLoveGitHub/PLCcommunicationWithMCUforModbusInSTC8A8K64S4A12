#ifndef __REGISTER_H
#define __REGISTER_H
#include "type.h"

#define REGISTER_DATA_LEN 50
#define MODBUS_MAX_PACKET_LEN 50
#define rtu_address 0x1
#define TEST_ADDRESS0_DATA 0x0000
#define TEST_ADDRESS1_DATA 0x9876
#define REG_MODBUS_OPR_MULTI_READ   0x03
#define REG_MODBUS_OPR_MULTI_WRITE  0x10
#define REG_MODBUS_OPR_SINGLE_WRITE 0x06
#define BIT_MODBUS_OPR_READ			0x01
#define BIT_MODBUS_OPR_WRITE		0x05
#define REG_MODBUS_READ_INPUT_REGISTER 0x04

#define REG_PUTCHAR   SendData



u8 reg_command_receive(u8 rdata);
u8 reg_write(u16 reg_address, void *reg_value, u16 len);
u8 reg_read(u16 reg_address, void *reg_value, u16 len);
void reg_init(void);
void reg_monitor(void);
extern void Notify_ModbusRtu_Register_IsReceived_Message(void);


#endif
