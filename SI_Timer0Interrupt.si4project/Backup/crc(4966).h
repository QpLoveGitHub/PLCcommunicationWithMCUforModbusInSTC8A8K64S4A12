
#ifndef CRC_H
#define CRC_H

#ifdef __cplusplus
extern "C"
{
#endif

unsigned short crc16(unsigned short nCrc, unsigned char *buf, int len);
unsigned short modbus_crc16(const unsigned char *buf, unsigned int len);
unsigned char modbus_crc16_check(unsigned char *buf, unsigned short buf_len);

#ifdef __cplusplus
}
#endif

#endif

