/*

	About: Convert Russian text to pawn include v1.3
	Author: Noname

*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before m_crp"
#endif

#if defined _m_crp_included_
	#endinput
#endif
#define _m_crp_included_

/*
	Define const
*/

#if !defined MAX_CRP_SIZE
	#define MAX_CRP_SIZE 256
#endif

/*
	Natives
*/

native Text:__m_crp__TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
native __m_crp__TextDrawSetString(Text:text, string[]) = TextDrawSetString;
native PlayerText:__m_crp__CreatePlayerTextDraw(playerid, Float:x, Float:y, const text[]) = CreatePlayerTextDraw;
native __m_crp__PlayerTextDrawSetStrin(playerid, PlayerText:text, const string[]) = PlayerTextDrawSetString;

/*
	Vars
*/

static const
	crp_server_text_aya[] = {"aó¢ôöeõüúùkûØÆo£pc¶yÅxâ§•°ß®©™´¨"}, // Ù, ˆ
	crp_server_text_AYA[] = {"AÄãÇÉEÑàÖÜKáMHOåPCèYÅXâçéäêëíìîï"};

/*
	Private functions
*/

static stock ConvertRusToPwn(const string[], buffer[])
{
	for (new c, i; (c = string[i]) != '\0'; i++) {
		switch (c) {
			case '‡'..'ˇ':
				buffer[i] = crp_server_text_aya[c - '‡'];
			case '¿'..'ﬂ':
				buffer[i] = crp_server_text_AYA[c - '¿'];
			case '∏':
				buffer[i] = 'e';
			case '®':
				buffer[i] = 'E';
			default:
				buffer[i] = c;
		}
	}
}

/*
	GameTextForAll
*/

stock CRusToPwn_GameTextForAll(const string[], time, style)
{
	new
		info[MAX_CRP_SIZE + 1];

	ConvertRusToPwn(string, info);
	return GameTextForAll(info, time, style);
}
#if defined _ALS_GameTextForAll
	#undef GameTextForAll
#else
	#define _ALS_GameTextForAll
#endif

#define GameTextForAll( CRusToPwn_GameTextForAll(

/*
	GameTextForPlayer
*/

stock CRusToPwn_GameTextForPlayer(playerid, const string[], time, style)
{
	new
		info[MAX_CRP_SIZE + 1];

	ConvertRusToPwn(string, info);
	return GameTextForPlayer(playerid, info, time, style);
}
#if defined _ALS_GameTextForPlayer
	#undef GameTextForPlayer
#else
	#define _ALS_GameTextForPlayer
#endif

#define GameTextForPlayer( CRusToPwn_GameTextForPlayer(

/*
	TextDrawCreate
*/

stock Text:CRusToPwn_TextDrawCreate(Float:x, Float:y, const text[])
{
	new
		info[MAX_CRP_SIZE + 1];

	ConvertRusToPwn(text, info);
	return __m_crp__TextDrawCreate(x, y, info);
}
#if defined _ALS_TextDrawCreate
	#undef TextDrawCreate
#else
	#define _ALS_TextDrawCreate
#endif

#define TextDrawCreate( CRusToPwn_TextDrawCreate(

/*
	TextDrawSetString
*/

stock CRusToPwn_TextDrawSetString(Text:text, const string[])
{
	new
		info[MAX_CRP_SIZE + 1];

	ConvertRusToPwn(string, info);
	return __m_crp__TextDrawSetString(text, info);
}
#if defined _ALS_TextDrawSetString
	#undef TextDrawSetString
#else
	#define _ALS_TextDrawSetString
#endif

#define TextDrawSetString( CRusToPwn_TextDrawSetString(

/*
	CreatePlayerTextDraw
*/

stock PlayerText:CRusToPwn_CreatePlayerTextDraw(playerid, Float:x, Float:y, const text[])
{
	new
		info[MAX_CRP_SIZE + 1];

	ConvertRusToPwn(text, info);
	return __m_crp__CreatePlayerTextDraw(playerid, x, y, info);
}
#if defined _ALS_CreatePlayerTextDraw
	#undef CreatePlayerTextDraw
#else
	#define _ALS_CreatePlayerTextDraw
#endif

#define CreatePlayerTextDraw( CRusToPwn_CreatePlayerTextDraw(

/*
	PlayerTextDrawSetString
*/

stock CRusToPwn_PlayerTextDrawSetStr(playerid, PlayerText:text, const string[])
{
	new
		info[MAX_CRP_SIZE + 1];

	ConvertRusToPwn(string, info);
	return __m_crp__PlayerTextDrawSetStrin(playerid, text, info);
}
#if defined _ALS_PlayerTextDrawSetString
	#undef PlayerTextDrawSetString
#else
	#define _ALS_PlayerTextDrawSetString
#endif

#define PlayerTextDrawSetString( CRusToPwn_PlayerTextDrawSetStr(