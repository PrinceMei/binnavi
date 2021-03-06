// Copyright 2011-2016 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifdef WINCE

#ifndef WINVER
#define WINVER 0x420
#endif

#ifndef MAX_MSG
#define MAX_MSG 100
#endif

#include "ListBoxWMTarget.hpp"

namespace zylib
{
	namespace zylog
	{
		ListBoxTarget::ListBoxTarget(const HWND hDlg, const int itemID) //: ILogTarget()
		{
			hListBox = GetDlgItem( hDlg, itemID );
		}

		void ListBoxTarget::log(const char* msg)
		{
			//dirty conversion
			unsigned int len = strlen(msg);
			if (len > MAX_MSG)
				len = MAX_MSG;
			//wchar_t* wmsg = new wchar_t[len + 1];
			wchar_t* wmsg = (wchar_t*) malloc((len+1)*sizeof(wchar_t));

			for (unsigned int i=0; i<= len; i++)
				wmsg[i] = msg[i];

			ListBox_AddString( hListBox, wmsg);
			int count = ListBox_GetCount( hListBox );
			ListBox_SetTopIndex( hListBox, count-1 );

			free(wmsg);
		}
	}
}

#endif