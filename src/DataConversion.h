// DataConversion
// @author     : Hakan Kaya
// @created    : 16.11.2022
// @description:
//

#ifndef DATACONVERSION_H
#define DATACONVERSION_H

#include <QtWidgets>

//-------------------------------------------------------------------------------------------------

/// Convert bool to QByteArray
/// \param value
/// \return
inline QByteArray convertBoolToByteArray(bool value) {
    QByteArray byteArray;
    byteArray.resize(1);
    byteArray[0] = value;
    return byteArray;
}

/// Converts a QByteArray to a bool
/// \param byteArray
/// \return
inline bool convertByteArrayToBool(QByteArray byteArray) {
    return byteArray[0];
}

//-------------------------------------------------------------------------------------------------

/// Convert int to QByteArray
/// \param value
/// \return 1 byte array
inline QByteArray convertCharToByteArray(char value) {
    QByteArray byteArray;
    byteArray.resize(1);
    byteArray[0] = value;
    return byteArray;
}

/// Converts a QByteArray to a char
/// \param byteArray
/// \return
inline char convertByteArrayToChar(QByteArray byteArray) {
    return byteArray[0];
}

//-------------------------------------------------------------------------------------------------
/// Converts a QByteArray to an int
/// \param byteArray
/// \return
inline int convertByteArrayToInt(QByteArray byteArray) {
    return (byteArray[0] << 8) | byteArray[1];
}

/// Convert int to QByteArray
/// \param value
/// \return 2 byte array
inline QByteArray convertIntToByteArray(int value) {
    QByteArray byteArray;
    byteArray.resize(2);
    byteArray[0] = (value >> 8) & 0xFF;
    byteArray[1] = value & 0xFF;
    return byteArray;
}

//-------------------------------------------------------------------------------------------------
/// Converts a float to a QByteArray
/// \param value
/// \return 4 byte array
inline QByteArray convertFloatToByteArray(float value) {
    QByteArray byteArray;
    QDataStream streamSlider3(&byteArray, QIODevice::WriteOnly);
    streamSlider3.setFloatingPointPrecision(QDataStream::SinglePrecision);
    streamSlider3.setByteOrder(QDataStream::BigEndian);
    streamSlider3 << value;
    return byteArray;
}

/// Converts a QByteArray to a float
/// \param byteArray
/// \return
inline float convertByteArrayToFloat(QByteArray byteArray) {
    float value;
    QDataStream streamSlider3(&byteArray, QIODevice::ReadOnly);
    streamSlider3.setFloatingPointPrecision(QDataStream::SinglePrecision);
    streamSlider3.setByteOrder(QDataStream::BigEndian);
    streamSlider3 >> value;
    return value;
}

//-------------------------------------------------------------------------------------------------
/// Converts a uint8_t to a QByteArray
/// \param value
/// \return
inline QByteArray convertUint8ToByteArray(uint8_t value) {
    QByteArray byteArray;
    byteArray.resize(1);
    byteArray[0] = value;
    return byteArray;
}

/// Converts a QByteArray to a uint8_t
/// \param byteArray
/// \return
inline uint8_t convertByteArrayToUint8(QByteArray byteArray) {
    return byteArray[0];
}

//-------------------------------------------------------------------------------------------------
/// Converts a uint16_t to a QByteArray
/// \param byteArray
/// \return
inline uint16_t convertByteArrayToUint16(QByteArray byteArray){
    return (byteArray[0] << 8 ) | (byteArray[1] & 0xFF);
}

/// Converts a QByteArray to a uint16_t
/// \param value
/// \return
inline QByteArray convertUint16ToByteArray(uint16_t value) {
    QByteArray byteArray;
    byteArray.resize(2);
    byteArray[0] = (value >> 8) & 0xFF;
    byteArray[1] = value & 0xFF;
    return byteArray;
}

//-------------------------------------------------------------------------------------------------

/// Converts a uint32_t to a QByteArray
/// \param byteArray
/// \return
inline uint32_t convertByteArrayToUint32(QByteArray byteArray){
    return (byteArray[0] << 24 ) | (byteArray[1] << 16 ) | (byteArray[2] << 8 ) | (byteArray[3] & 0xFF);
}

/// Converts a QByteArray to a uint32_t
/// \param value
/// \return
inline QByteArray convertUint32ToByteArray(uint32_t value) {
    QByteArray byteArray;
    byteArray.resize(4);
    byteArray[0] = (value >> 24) & 0xFF;
    byteArray[1] = (value >> 16) & 0xFF;
    byteArray[2] = (value >> 8) & 0xFF;
    byteArray[3] = value & 0xFF;
    return byteArray;
}

//-------------------------------------------------------------------------------------------------

inline QString convertByteArrayToQString(QByteArray byteArray) {
    return QString::fromUtf8(byteArray);
}

inline QByteArray convertQStringToByteArray(QString string) {
    return string.toUtf8();
}

//-------------------------------------------------------------------------------------------------


/*********************************************************************************************************************
 * C based conversion functions
 *********************************************************************************************************************/

/// Convert int to byte array
/// \param value
/// \return
inline unsigned char* convertFloatToBytes(float value) {
    // convert float to byte array with ieee 754 format
    unsigned char* byteArray = new unsigned char[4];
    unsigned char* floatToConvert = (unsigned char*)&value;
    byteArray[0] = floatToConvert[3];
    byteArray[1] = floatToConvert[2];
    byteArray[2] = floatToConvert[1];
    byteArray[3] = floatToConvert[0];
    return byteArray;
}

/// Converts a bytes to a float
/// \param byteArray
/// \return
inline float convertBytesToFloat(unsigned char* byteArray) {
    // convert byte array with ieee 754 format to float
    unsigned char floatToConvert[4];
    floatToConvert[0] = byteArray[3];
    floatToConvert[1] = byteArray[2];
    floatToConvert[2] = byteArray[1];
    floatToConvert[3] = byteArray[0];
    float* value = (float*)floatToConvert;
    return *value;
}


#endif //DATACONVERSION_H
