#pragma once
#include "clsScreen.h"  ; 
#include "clsBankClient.h" ; 
class clsTransfarLogScreen : protected clsScreen
{
private : 
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLog) {
		cout << setw(8) << left << "" << "| " << left << setw(20) << TransferLog.DateTime;
		cout << "| " << left << setw(12) << TransferLog.SAccountNumber;
		cout << "| " << left << setw(12) << TransferLog.DAccountNumber;
		cout << "| " << left << setw(10) << TransferLog.Amount;
		cout << "| " << left << setw(10) << TransferLog.SAccountBalance;
		cout << "| " << left << setw(18) << TransferLog.DAccountBalance;
		cout << "| " << left << setw(16) << TransferLog.UserName;
	}
public : 
	static void ShowTransfarLogScreen() {
		vector<clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
		string Title = "\tTransfar Log List Screen";
		string SubTitle = "(" + to_string(vTransferLogRecord.size()) + ")Record(s)";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t________________________________";
		cout << "__________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(12) << "s.Acct";
		cout << "| " << left << setw(12) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(18) << "d.Balance";
		cout << "| " << left << setw(16) << "User";
		cout << setw(8) << left << "" << "\n\t________________________________";
		cout << "__________________________________________________________________\n" << endl;
		if (vTransferLogRecord.size() == 0) {
			cout << "\t\t\t\tNo Transfers Available In the System!"; 
		}
		else {
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord) {
				_PrintTransferLogRecordLine(Record);
			}


		}
	}
};

