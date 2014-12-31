/* 
 * File:   SocketInputStream.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月31日, 上午10:55
 */

#ifndef CN_VICKY__SOCKETINPUTSTREAM_H
#define	CN_VICKY__SOCKETINPUTSTREAM_H


#include "../engine-socket/Socket.h"

#define PACK_COMPART "$-$"//封包分隔符
#define PACK_COMPART_SIZE strlen(PACK_COMPART)

//初始化的接收缓存长度
#define DEFAULTSOCKETINPUTBUFFERSIZE    64*1024
//最大可以允许的缓存长度，如果超过此数值，则断开连接
#define DISCONNECTSOCKETINPUTSIZE       96*1024

class SocketInputStream {
public:
    SocketInputStream(Socket* sock,
            UINT BufferSize = DEFAULTSOCKETINPUTBUFFERSIZE,
            UINT MaxBufferSize = DISCONNECTSOCKETINPUTSIZE);
    virtual ~SocketInputStream();


public:
    UINT Read(CHAR* buf, UINT len);
//    BOOL ReadPacket(Packet* p);

    BOOL Peek(CHAR* buf, UINT len);

    BOOL Find(CHAR* buf);

    BOOL Skip(UINT len);

    UINT Fill();
    UINT Fill_RAW();

    VOID Initsize();
    BOOL Resize(INT size);

    UINT Capacity()const {
        return m_BufferLen;
    }

    UINT Length()const;

    UINT Size()const {
        return Length();
    }

    BOOL IsEmpty()const {
        return m_Head == m_Tail;
    }

    VOID CleanUp();

    UINT GetHead() {
        return m_Head;
    }

    UINT GetTail() {
        return m_Tail;
    }

    UINT GetBuffLen() {
        return m_BufferLen;
    }

    CHAR* GetBuff() {
        return m_Buffer;
    }
private:
    Socket* m_pSocket;

    CHAR* m_Buffer;

    UINT m_BufferLen;
    UINT m_MaxBufferLen;

    UINT m_Head;
    UINT m_Tail;

};


#endif	/* CN_VICKY__SOCKETINPUTSTREAM_H */

