//
//  weapons.cp
//  gtm
//
/*
 GNU LESSER GENERAL PUBLIC LICENSE
 Version 3, 29 June 2007
 
 Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
 
 
 This version of the GNU Lesser General Public License incorporates
 the terms and conditions of version 3 of the GNU General Public
 License, supplemented by the additional permissions listed below.
 
 0. Additional Definitions.
 
 As used herein, "this License" refers to version 3 of the GNU Lesser
 General Public License, and the "GNU GPL" refers to version 3 of the GNU
 General Public License.
 
 "The Library" refers to a covered work governed by this License,
 other than an Application or a Combined Work as defined below.
 
 An "Application" is any work that makes use of an interface provided
 by the Library, but which is not otherwise based on the Library.
 Defining a subclass of a class defined by the Library is deemed a mode
 of using an interface provided by the Library.
 
 A "Combined Work" is a work produced by combining or linking an
 Application with the Library.  The particular version of the Library
 with which the Combined Work was made is also called the "Linked
 Version".
 
 The "Minimal Corresponding Source" for a Combined Work means the
 Corresponding Source for the Combined Work, excluding any source code
 for portions of the Combined Work that, considered in isolation, are
 based on the Application, and not on the Linked Version.
 
 The "Corresponding Application Code" for a Combined Work means the
 object code and/or source code for the Application, including any data
 and utility programs needed for reproducing the Combined Work from the
 Application, but excluding the System Libraries of the Combined Work.
 
 1. Exception to Section 3 of the GNU GPL.
 
 You may convey a covered work under sections 3 and 4 of this License
 without being bound by section 3 of the GNU GPL.
 
 2. Conveying Modified Versions.
 
 If you modify a copy of the Library, and, in your modifications, a
 facility refers to a function or data to be supplied by an Application
 that uses the facility (other than as an argument passed when the
 facility is invoked), then you may convey a copy of the modified
 version:
 
 a) under this License, provided that you make a good faith effort to
 ensure that, in the event an Application does not supply the
 function or data, the facility still operates, and performs
 whatever part of its purpose remains meaningful, or
 
 b) under the GNU GPL, with none of the additional permissions of
 this License applicable to that copy.
 
 3. Object Code Incorporating Material from Library Header Files.
 
 The object code form of an Application may incorporate material from
 a header file that is part of the Library.  You may convey such object
 code under terms of your choice, provided that, if the incorporated
 material is not limited to numerical parameters, data structure
 layouts and accessors, or small macros, inline functions and templates
 (ten or fewer lines in length), you do both of the following:
 
 a) Give prominent notice with each copy of the object code that the
 Library is used in it and that the Library and its use are
 covered by this License.
 
 b) Accompany the object code with a copy of the GNU GPL and this license
 document.
 
 4. Combined Works.
 
 You may convey a Combined Work under terms of your choice that,
 taken together, effectively do not restrict modification of the
 portions of the Library contained in the Combined Work and reverse
 engineering for debugging such modifications, if you also do each of
 the following:
 
 a) Give prominent notice with each copy of the Combined Work that
 the Library is used in it and that the Library and its use are
 covered by this License.
 
 b) Accompany the Combined Work with a copy of the GNU GPL and this license
 document.
 
 c) For a Combined Work that displays copyright notices during
 execution, include the copyright notice for the Library among
 these notices, as well as a reference directing the user to the
 copies of the GNU GPL and this license document.
 
 d) Do one of the following:
 
 0) Convey the Minimal Corresponding Source under the terms of this
 License, and the Corresponding Application Code in a form
 suitable for, and under terms that permit, the user to
 recombine or relink the Application with a modified version of
 the Linked Version to produce a modified Combined Work, in the
 manner specified by section 6 of the GNU GPL for conveying
 Corresponding Source.
 
 1) Use a suitable shared library mechanism for linking with the
 Library.  A suitable mechanism is one that (a) uses at run time
 a copy of the Library already present on the user's computer
 system, and (b) will operate properly with a modified version
 of the Library that is interface-compatible with the Linked
 Version.
 
 e) Provide Installation Information, but only if you would otherwise
 be required to provide such information under section 6 of the
 GNU GPL, and only to the extent that such information is
 necessary to install and execute a modified version of the
 Combined Work produced by recombining or relinking the
 Application with a modified version of the Linked Version. (If
 you use option 4d0, the Installation Information must accompany
 the Minimal Corresponding Source and Corresponding Application
 Code. If you use option 4d1, you must provide the Installation
 Information in the manner specified by section 6 of the GNU GPL
 for conveying Corresponding Source.)
 
 5. Combined Libraries.
 
 You may place library facilities that are a work based on the
 Library side by side in a single library together with other library
 facilities that are not Applications and are not covered by this
 License, and convey such a combined library under terms of your
 choice, if you do both of the following:
 
 a) Accompany the combined library with a copy of the same work based
 on the Library, uncombined with any other library facilities,
 conveyed under the terms of this License.
 
 b) Give prominent notice with the combined library that part of it
 is a work based on the Library, and explaining where to find the
 accompanying uncombined form of the same work.
 
 6. Revised Versions of the GNU Lesser General Public License.
 
 The Free Software Foundation may publish revised and/or new versions
 of the GNU Lesser General Public License from time to time. Such new
 versions will be similar in spirit to the present version, but may
 differ in detail to address new problems or concerns.
 
 Each version is given a distinguishing version number. If the
 Library as you received it specifies that a certain numbered version
 of the GNU Lesser General Public License "or any later version"
 applies to it, you have the option of following the terms and
 conditions either of that published version or of any later version
 published by the Free Software Foundation. If the Library as you
 received it does not specify a version number of the GNU Lesser
 General Public License, you may choose any version of the GNU Lesser
 General Public License ever published by the Free Software Foundation.
 
 If the Library as you received it specifies that a proxy can decide
 whether future versions of the GNU Lesser General Public License shall
 apply, that proxy's public statement of acceptance of any version is
 permanent authorization for you to choose that version for the
 Library.
 */

#include "weapons.h"
#include "IniFile.h"
#include "regexlib.h"
#include <boost/assign/list_of.hpp>
#include <boost/regex.hpp>
#include "rcon.h"

using namespace std;
using namespace boost;

int WeaponProcessor::Process(string value) {
	smatch result;
	
	if (regex_search(value, result, regexlib::killLineWeapon)) {
		if (!IsAllowed(result[10])) {
            string weaponName = databaseManager->GetResultData().at(1).c_str();
            cout << "Kicking player" << result[9] << endl;
            string kickSay = "say ^2Kicking player ^1" + result[9] + " ^2for using ^1" + weaponName;
            string kickLine = "clientkick "+result[6]+" "+weaponName+" is not allowed on this server!";
            Rcon::GetInstance().SendQuickRcon(kickSay);
            Rcon::GetInstance().SendQuickRcon(kickLine);
			// kick
		} else {
            // cout << result[2] << endl; // pid
            // cout << result[5] << endl; // pusername
            // result[11] // damage
            // result[13] // hitzone
            
			// kill
            if (0 == databaseManager->IsPlayerInDatabase(result[2])) {
                if (!databaseManager->InsertPlayer(result[2], result[5])) {
                    cout << "Error! Cant write database entry for new player " << result[2] << endl;
                    return false;
                }
            }
            
            // write kill stats to database
            string query = "UPDATE user_stats SET ";
            if (result[4] != result[8]) {
                query += "kill_count = kill_count + 1";
            } else {
                query += "teamkill_count =teamkill_count + 1";    
            }
            
            query += " where playerid = " + result[2];
            if (databaseManager->Exec(query) != SQLITE_OK) {
                cout << databaseManager->GetErrorChar() << endl;
                cout << "Cant write stats query" << endl;
            }
			if (result[4] != result[8]) {
				// killed 
				if (0 == databaseManager->IsPlayerInDatabase(result[6])) {
					if (!databaseManager->InsertPlayer(result[6], result[9])) {
						cout << "Error! Cant write database entry for new player " << result[6] << endl;
						return false;
					}
				}
				// write kill stats to database
				query = "";
				query = "UPDATE user_stats SET ";
            
                query += "death_count = death_count + 1";
				query += " where playerid = " + result[6];
				if (databaseManager->Exec(query) != SQLITE_OK) {
					cout << databaseManager->GetErrorChar() << endl;
					cout << "Cant write stats query" << endl;
				}
            }
        }
		return true;
	}
	return false;
}

bool WeaponProcessor::IsAllowed(string weapon) {
	smatch result; 
    
	weaponsIt = weapons.begin();
	/**
	 * we need to extract the weapon and match it against our settings
	 * if weapon is allowed we search in the next step for addons 
	 */
	if (regex_search(weapon, result, regexlib::extractWeaponName_VariationOne)) {
		weaponsIt = weapons.find(result[0]);
		if (weaponsIt != weapons.end()) {
            string query = "SELECT * FROM weapon WHERE id = " + weaponsIt->second + " AND is_allowed = 0 LIMIT 1;";
            if (databaseManager->Exec(query) != SQLITE_OK) {
                cout << "Cant lookup weapon database with weapon 1 " << weaponsIt->second << endl;
            }
            if (1 == databaseManager->GetNumOfRows()) {
                return false;
            }
		}
	}
	
	weaponsIt = weapons.begin();
	/**
	 * we search for weapon addons first before we crawl 
	 * weapons with name containing 2 _
	 */
	if (regex_search(weapon, result, regexlib::extractWeaponAddon_VariationOne)) {
		weaponsIt = weapons.find(result[1]);
		if (weaponsIt != weapons.end()) {
            string query = "SELECT * FROM weapon WHERE id = " + weaponsIt->second + " AND is_allowed = 0 LIMIT 1;";
            if (databaseManager->Exec(query) != SQLITE_OK) {
                cout << "Cant lookup weapon database with addon 1 " << weaponsIt->second << endl;
            }
            if (1 == databaseManager->GetNumOfRows()) {
                return false;
            }
		}
	}
	
	/**
	 * The second run gets sure if multiple addons are
	 * attached
	 */
	if (regex_search(weapon, result, regexlib::extractWeaponAddon_VariationTwo)) {
		weaponsIt = weapons.find(result[1]);
		if (weaponsIt != weapons.end()) {
			string query = "SELECT * FROM weapon WHERE id = " + weaponsIt->second + " AND is_allowed = 0 LIMIT 1;";
            if (databaseManager->Exec(query) != SQLITE_OK) {
                cout << "Cant lookup weapon database with addon 2 " << weaponsIt->second << endl;
            }
            if (1 == databaseManager->GetNumOfRows()) {
                return false;
            }
		}
	}
	
	if (regex_search(weapon, result, regexlib::extractWeaponName_VariationTwo)) {
		weaponsIt = weapons.find(result[0]);
		if (weaponsIt != weapons.end()) {
			string query = "SELECT * FROM weapon WHERE id = " + weaponsIt->second + " AND is_allowed = 0 LIMIT 1;";
            if (databaseManager->Exec(query) != SQLITE_OK) {
                cout << "Cant lookup weapon database with weapon 2 " << weaponsIt->second << endl;
            }
            if (1 == databaseManager->GetNumOfRows()) {
                return false;
            }		
        }
	}
	return true;
}

WeaponProcessor::WeaponProcessor() {
    
    databaseManager = &Database::GetInstance();

	weapons = assign::map_list_of 
	("mp5k_",		"1")
	("skorpion_",	"2")
	("mac11_",		"3")
	("ak74u_",		"4")
	("uzi_",        "5")
	("pm63_",		"6")
	("mpl_",		"7")
	("spectre_",	"8")
	("kiparis_",	"9")
	("m16_",		"10")
	("enfield_",	"11")
	("m14_",		"12")
	("famas_",		"13")
	("galil_",		"14")
	("aug_",		"15")
	("fnfal_",		"16")
	("ak47_",		"17")
	("commando_",	"18")
	("g11_",		"19")
	("olympia_",	"20")
	("stakeout_",	"21")
	("spas_",		"22")
	("hs10_",		"23")
	("hk21_",		"24")
	("rpk_",		"25")
	("m60_",		"26")
	("stoner63_",	"27")
	("dragunov_",	"28")
	("wa2000_",		"29")
	("l96a1_",		"30")
	("psg1_",		"31")
	("asp_",		"32")
	("m1911_",		"33")
	("makarov_",	"34")
	("python_",		"35")
	("CZ75_",		"36")
	("law_",		"37")
	("rpg_",		"38")
	("strela_",		"39")
	("china_",		"40")
	("crossbow_",	"41")
	("explosive_bolt_", "42")
	("_gl",			"43")
	("_mk",			"44")
	("_ft",			"45")
	("_dw",			"46")
	("_dualclip",	"47")
	("_extclip",	"48")
	("_silencer",	"49")
	("_elbit",		"50")
	("_acog",		"51")
	("_reflex",		"52")
	("_lps",		"53")
	("_vzoom",		"54")
	("_auto",		"55")
	("_speed",		"56")
	("_snub",		"57")
	("_grip",		"58")
	("_upgradesight",	"59")
	("_ir",			"60")
	("_rf",			"61")
	("rcbomb_",		"62")
	("napalm_",		"63")
	("autoturret_",	"64")
	("mortar_",		"65")
	("cobra_",		"66")
	("m220_tow_",	"67")
	("airstrike_",	"68")
	("huey_",		"69")
	("hind_",		"70")
	("dog_",		"71")
	("m202_flash_",	"72")
	("minigun_",	"73")
	("knife_",	"74")
	("frag_grenade_",	"75")
	("sticky_",		"76")
	("hatchet_",	"77")
	("willy_pete_",	"78")
	("flash_grenade_",	"79")
	("concussion_",	"80")
	("tabun_gas_",	"81")
	("nightingale_",	"82")
	("claymore_",	"83")
	("c4_",		"84");
}