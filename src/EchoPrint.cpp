// EchoPrint.cpp
// Changed
//
// EchoPrint codegen wrapper for SampleShipper
//
// Takes Audio object, extracts PCM, recieves Codegen response

#include "EchoPrint.h"

using namespace std;

//const string CODEGEN_PATH =
//"../lib/echoprint-codegen/echoprint-codegen";

string EchoPrint::ID(string filename){
	string songCode = codegen(filename);
	cout << "I, ID, have the code: " + songCode << endl;
	string rawSongInfo = echoServer(songCode);
	cout << endl << endl << "I, ID, have fingerprinting with the following JSON info: " << rawSongInfo << endl;
	return "done";
}

string EchoPrint::JSONtoCode(string codegenOutput){

	FILE* fp = fopen(codegenOutput.c_str(), "r");

	char readBuffer[65536];
	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	rapidjson::Document codegenJSON;
	codegenJSON.ParseStream(is);
	fclose(fp);

	//rapidjson::Document codegenJSON;

	//codegenJSON.Parse(codegenOutput.c_str());
	assert(codegenJSON.IsObject());	
	assert(codegenJSON.HasMember("metadata"));
	string bitrate = codegenJSON["metadata"]["filename"].GetString();
	string code = codegenJSON["code"].GetString();
	cout << "Hello from JSONtoCode, I found metadata.filename to be: " + bitrate << endl;
	return code;
}


//Calls codegen, returns codegen output (songCode)
string EchoPrint::codegen(string filename){

	popen("./lib/echoprint-codegen/echoprint-codegen ./src/data/hung21.mp3", "r");
	cout << "Wait for codegen";
	cin.ignore();
	return JSONtoCode("./bin/json/out.json");
}



std::string buffer;

size_t curl_write( void *ptr, size_t size, size_t nmemb, void *stream)
{
	buffer.append((char*)ptr, size*nmemb);
	return size*nmemb;
}

//Sends songCode to echoPrint server, returns result (rawSongInfo)
string EchoPrint::echoServer(string songCode){

	
	char codeSendRequest[4096] = "";
	strcpy(codeSendRequest, "http://1.1.1.127:8080/query?fp_code=eJzVmVFubSsORKcEB\
	mwYDtgw_yH0Iq1-6Rsp5CN6et26Un3s7MMBu1xVnJtSSjs9oKQX1PKCPV9w9gOytBfUeIG9Q\
	Np6QS8PKNZe0PcL1nxATfKCEi9o_QX3y7-FlNoLpL_g3f1TH5DzE6q-YMgL5nnAu79y-gOKt\
	heM9ICa7AVSXtDrC-IFSewF7w4Oe8GRB_zUwfwAuSP-PZTzgh_6ux5QLL9gzhf4E855QFV5w\
	Yc8fAshL9jnASmtF8h5QSsv-JW2P5nj_oL9gp-4MR5QTF5w_ex72O0BPyjDXf57WOMFoQ9Iq\
	b_gN8r_G268u395-S1Ibi-4gvc9fGjlt_CbVPD0hR-4If6CX3ADDX_B39f90V8Q5wU_MMce8\
	Kv-3hj1Pby7_xtl-N_s_g_9fWeGf6iDN1R-Dz_0t77g_7K_T3j392-b0LzWA37V_fSE3_TX7\
	QE1xwt-4-zbvgUvYr149DqaaTHPfe4aZU8Lt3nmrMmzaz6zBQWYzZdEpHpOWFeJM-Q073WJR\
	lfrtacWVfeKMTWL1ZJ3NQ0aU6S7ln2qVnUrnXEJmSLa2nKRfWYdx7vu7KnVvVeG2VIraexUX\
	62z08T7VMvz6SdW02ynkXxbbtEtho-dVE9takP3GaeZrMo1f4w5g7dr8dLG7niPiYkWXOiUt\
	ZfvXHJptnKauxcr-Ti3aZ37-NylkvmLyNxLVivNp7Qzl_iMErvH7GdquJ_Mat5mUS8leTunl\
	DrZS7HY61LIlGtY1pwlDWnKEmvs3Izy17SLFJK4aqyTZdqcR2cXSX0olWfUZ5hRPS19qpVVt\
	_JaiTF4S7UVFtzU6i_wqGt9efYJOccm7pwx0duZZm70JnsZNlk_ldI4zK3TGipk5gMt7oy5N\
	S-LEvZos9YRVkc5fLprGasMLs-cN2Zx0hJn3-v0yTpuvFmmOCVtddZGKYrsJNPn5IBeD_VZt\
	HJBNhVemDurJQkfKWqDT5Gnt8xdqLMfux2gB8Nn7i3nembkutNpPWIPD2lD-e7WWt8mPSevR\
	m3pSlJjmdWW0HAZ26pXUSjlSbcE9Rl1roYoTL7R1PJhY3BZes3c03Iea9bDrpbYgg8wH1aas\
	YVxxpDdssFodlprCztrWu6ULnRW5K9Wj5NH9bHOPsIn52FjOzMxkYmvEKJGs0m0L2e6dNmun\
	pnp9QlMSdQvzz6BAtHJWsb27m3bKW2LtblHC7iSjUoPvYIqWWnMqpMh3qs2DsRsOycsWQvV0\
	1uAIhQw8VpW7cm8jby2G9FlzaCWZUmnOtUFegzGVUs1X25jHqrZR0nBmHDU7mnXWaybQ66wz\
	PbSKWy11jzMp1-DoAloymSm075awdfsSw1jFKgjNjGv_dHX2EptSxxpi57GKogUPecNybMVR\
	qVqTAau0HdGbUra9CO6o18zmxzLkyFbbLfvVN2EwlL2iMgR0iFkZ-wpuRI-V_BpNGpA68gDa\
	WMKbz9qOsJQ0XzYOge6ipqsvJErqQxBwwvY7pkjIbEGoZz50DsupTYErndfoWtPZp1BOQy3z\
	JJltO3NDxKASkJc-M1mOkID9dd0qhLR1_kERMzHl2ef0HUdeIEQtXXUhEZRp3M7Nke9BG5p0\
	KM2DRGkqQMphjS0snm7M6Psdeqh0QhwYzycbYdz1KuVKkj83QFNnrAFc8VNbuXq4SGOyNgEU\
	7FPZn1JLrdIaCRSs1BCz8uuyEtnKFdHPvI2TStD0rShp8ekP6s4aYJLalfESNH61SkxPcqd8\
	WSuNip_rrFdvhJapG8OJln2jsRQI38MYQmXidZgZocN2Mksg4GwGzZYJ3KNL7J4Rir3GKMMp\
	N9Raka86p2UXTVHO7Az7vIMTdtlbpQ68A6EzjZKjg9o5Ztzw-kSHbWz0acyTmpnQxJO0izxD\
	F1Igrsdzexq9VCY3ge6ydzF_VFmM8-7459l-5ldzyf4XLl_efYJKNCMdWdrCw3yRsYcMVXLP\
	KlICnQbr6xMsGk9SPEoGspZGDpOEC3vOZTmQptqd2wDTRkrshUcWWKkUaVhcXyK90Y-RxitK\
	NqvXza7qnSYJVLEudRrYzCWNigB7W_kiYIjDxkFMUKr4VjbHRvni6y1RN2df8cYc0LfFN0Mx\
	v1d_vIuUi8MIswQXIDG9M4I8WRVyn1Ww__CllI61TzN79hhVKwx-sikV9w3Ldq3Y6WxbmxAW\
	VBEXYplI_mL6pDOBsZM5DmoOVurdKMoB2EcWi7LCTR9hBTeadCqUq6FujA-IjmmMFnpEiVTC\
	0bWZYxlax-SQcPjYIjd9QfGdMdV64LA48THZ4M5QbM493S_NvofoKCEtz-ffQKVggecMHG2f\
	EV3jrbajWgGNakxpvEh7bBt5CC_YF0rn838w1zSFCvsMESs4Yh5LrpLfuNcdZIf5k0wtV_-3\
	XGRpQobOY0ZDlBgV3XKsnBUXOCGNDSHsIOSDEhxcKCMlTKWeCgt_pCbvPMehjksKFHXDQrVE\
	wJO1enXzkQ3OoNaIaAH8xYagCbMfEhQqBVxQhm4qPdn1ibIJ1PqyCrubLjY8GvQUIbwkHRgi\
	LgY7OitXM651kYQnYOMgRtdfnU_SLaSZzgcYsaQrqvFh_MupesDKccI6S4tugmbOFxk4fUMw\
	13vc6lq-Z6x3G0pFvrnZ5XMWce4eslJ5OOzeh00iKp7dcTiE5hVYs6fzz7BiYXWWODjqnTu1\
	JOTEqnvOgKf3K1nQoviu05UwEHRGCXVYwU4u9yFXNFXRjuRzrkCEG_gEkl1KspoTHLgYJmku\
	idp6xAqHFXhb5ukpdBfWjOvAz0txXfzGP1yEd2eWILBRKvMPqswm4d4PkjcOClagT7LuMLbc\
	MNrWpmaEMq9cYvZiOe51oPus29yQLkmT8RLt7_OwJFUlODWsWqyf0GcT4JzaLOTVHOiBluZx\
	YN0kOLHDo6J1DLuSDExxG6giEDzbaON3BI-lspy1-oQqTmK87He51Ll3_9Fxl_X8Dssf3yWr\
	EV-v8ZDIsME72cxUrZMsGGVK1N_AU-kfHn2X3_FI881zHT_i4TL9CHToqAFvxFagfYzfDdzG\
	vORLxP8pgzlFrBQL_QpZ73ZBLYsKpUgCjzD5wmAXBwzbrDIwIEeQzNGDaaSom5cCdTr4xSkl\
	30JCq1dshFvYE5KGNjG11fnioAOxOKUTYjSa7Y82Nb98WYbeZr3uBgTIgeBkLsfG2E_UJ-GV\
	3LmvZtxh-SOZbgheYpNE3qC0s8K3QqaRJ0SdAsJg5iyhACC4zUIds6--S31pJyASFksoWfET\
	2rYuSkMv9dIppmZoPddLsvipodVoGVBGaCg3CuEGbeOpeQzcjFXmYxtDG4JPLkxWlkJXm9ma\
	OyG7RJfiG20Bj0qB72bUnqugT8uPG3Rc4SC5DERYd5tg6vzJyQui1-f_QX_AtGpy0g=\0");
		


	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, codeSendRequest); 
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	fwrite( buffer.c_str(), buffer.length(), sizeof(char), stdout);

		
	return buffer;
}

