#include "Include/i2cctrl.h"

I2Cctrl* pInstI2C;

I2Cctrl::I2Cctrl()
{
}

__s32 I2Cctrl::i2c_smbus_access(int file, char read_write, __u8 command, int size, i2c_smbus_data *data)
{
    struct i2c_smbus_ioctl_data args;
    __s32 err;

    args.read_write = read_write;
    args.command = command;
    args.size = size;
    args.data = data;
    err = ioctl(file, I2C_SMBUS, &args);
    if (err == -1)
        err = -errno;
    return err;
}

__s32 I2Cctrl::i2c_smbus_read_byte_data(int file, __u8 command)
{
    union i2c_smbus_data data;
    if (i2c_smbus_access(file,I2C_SMBUS_READ,command,
                         I2C_SMBUS_BYTE_DATA,&data))
        return -1;
    else
        return data.byte;
}

__s32 I2Cctrl::i2c_smbus_read_word_data(int file, __u8 command)
{
    union i2c_smbus_data data;

    if (i2c_smbus_access(file,I2C_SMBUS_READ,command,
                         I2C_SMBUS_WORD_DATA,&data))
        return -1;
    else
        return data.word;
}

__s32 I2Cctrl::i2c_smbus_write_byte_data(int file, __u8 command, __u8 value)
{
    union i2c_smbus_data data;
    data.byte = value;
    if (i2c_smbus_access(file,I2C_SMBUS_WRITE,command,
                         I2C_SMBUS_BYTE_DATA,&data))
        return -1;
    else
        return data.byte;
}

__s32 I2Cctrl::i2c_smbus_write_word_data(int file, __u8 command, __u8 value)
{
    union i2c_smbus_data data;
    data.word = value;
    if (i2c_smbus_access(file,I2C_SMBUS_WRITE,command,
                         I2C_SMBUS_WORD_DATA,&data))
        return -1;
    else
        return data.word;
}

__s32 I2Cctrl::i2c_smbus_word_swap(__s32 word)
{
    return (((word & 0xff00) >> 8) | ((word & 0x00ff) << 8));
}


/**
 * @brief getI2Clib
 * @return 자신의 포인터
 */
I2Cctrl* InitI2C()
{
    if( 0 == pInstI2C)
        pInstI2C = new I2Cctrl();
    return pInstI2C;
}

I2Cctrl* GetI2C()
{
    return pInstI2C;
}

