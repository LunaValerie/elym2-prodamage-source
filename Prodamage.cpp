#pragma once
typedef D3DXVECTOR3 WaitHack;
DWORD SendBattleAttackPacketCall = 0x00CFC2E0; // Send Battle Attack Packet > Call
DWORD CPpythonNetworkSteam = *(DWORD*)0xF87474; // CPpythonNetworkSteam > String


typedef void(__thiscall* sendattack)(DWORD cpythonnetworkstream, UINT attack, DWORD vid, const WaitHack& m_iVecOrigin);
sendattack SendBattleAttackPacket = (sendattack)SendBattleAttackPacketCall;

bool dwProDamage17 = false;
float dwSpeed17 = 100.0f;

DWORD WINAPI x17(LPVOID lpParam)
{
	while (true)
	{
		if (dwProDamage17)
		{
			DWORD GetTargetVID = *reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(0x00F8BE94) + (0x00033FE4)); WaitHack dwVecOrigin; // GetTargetVID
			SendBattleAttackPacket(CPpythonNetworkSteam, 0, GetTargetVID, dwVecOrigin);
		}
		Sleep(dwSpeed17);
	}
}
