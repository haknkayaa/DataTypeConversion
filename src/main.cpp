#include <QApplication>
#include <QDebug>
#include <QtEndian>
#include <iostream>
#include <QDataStream>
#include "DataConversion.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    qDebug() << "QDataConversion";
    qDebug() << "---------------- Hakan Kaya ----------------";
    // for bool
    bool myBool = true;
    QByteArray myBoolByteArray = convertBoolToByteArray(myBool);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Bool value           : " << myBool;
    qDebug() << "Byte array of bool   : " << myBoolByteArray.toHex(':');
    qDebug() << "Bool from byte array : " << convertByteArrayToBool(myBoolByteArray);

    // for char
    char myChar = 'a';
    auto byteChar = convertCharToByteArray(myChar);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Char value           : " << myChar;
    qDebug() << "Byte array of char : " << byteChar.toHex(':');
    qDebug() << "Char from byte array : " << convertByteArrayToChar(byteChar);

    // for integer
    int myInt = 6;
    auto byteInt = convertIntToByteArray(myInt);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Int value           : " << myInt;
    qDebug() << "Byte array of int   : " << byteInt.toHex(':');
    qDebug() << "Int from byte array : " << convertByteArrayToInt(byteInt);

    // for float
    float myFloat = 123.04;
    auto byteFloat = convertFloatToByteArray(myFloat);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Float value           : " << myFloat;
    qDebug() << "Byte array of float   : " << byteFloat.toHex(':');
    qDebug() << "Float from byte array : " << convertByteArrayToFloat(byteFloat);

    uint8_t myUint8 = 123;
    auto byteUint8 = convertUint8ToByteArray(myUint8);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Uint8 value           : " << myUint8;
    qDebug() << "Byte array of uint8   : " << byteUint8.toHex(':');
    qDebug() << "Uint8 from byte array : " << convertByteArrayToUint8(byteUint8);

    uint16_t myUint16 = 123;
    auto byteUint16 = convertUint16ToByteArray(myUint16);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Uint16 value           : " << myUint16;
    qDebug() << "Byte array of uint16   : " << byteUint16.toHex(':');
    qDebug() << "Uint16 from byte array : " << convertByteArrayToUint16(byteUint16);

    uint32_t myUint32 = 123;
    auto byteUint32 = convertUint32ToByteArray(myUint32);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Uint32 value           : " << myUint32;
    qDebug() << "Byte array of uint32   : " << byteUint32.toHex(':');
    qDebug() << "Uint32 from byte array : " << convertByteArrayToUint32(byteUint32);

    QString myString = "hakan";
    auto byteString = convertQStringToByteArray(myString);
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "String value           : " << myString;
    qDebug() << "Byte array of string   : " << byteString.toHex(':');
    qDebug() << "String from byte array : " << convertByteArrayToQString(byteString);

    uint8_t hexValue = 0xC1;
    qDebug() << "-----------------------------------------------------------------------------";
    qDebug() << "Hex value           : " << hexValue;
    qDebug() << "Hex value to string : " << convertUint8ToByteArray(hexValue).toHex(':');

    printf("---------------------------------------------------------------------------\n");
    printf("C based conversion functions...\n");
    printf("---------------------------------------------------------------------------\n");

    float m_float = 123.04;
    unsigned char* m_floatByte = convertFloatToBytes(m_float);
    printf("---------------------------------------------------------------------------\n");
    printf("Float value           : %f\n", m_float);
    printf("Byte array of float   : %02X:%02X:%02X:%02X\n", m_floatByte[0], m_floatByte[1], m_floatByte[2], m_floatByte[3]);
    printf("Float from byte array : %f\n", convertBytesToFloat(m_floatByte));


    return a.exec();
}
