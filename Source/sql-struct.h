//
//  sql-struct.h
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

#ifndef __SQL_STRUCT__
#define __SQL_STRUCT__
#include <string>
std::string sqlStruct = "DROP TABLE IF EXISTS \"global_stats\";"
"CREATE TABLE \"global_stats\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"key\" text NOT NULL,"
"	 \"value\" integer NOT NULL"
");"
""
"DROP TABLE IF EXISTS \"group_permissions\";"
"CREATE TABLE \"group_permissions\" ("
"	 \"id\" integer NOT NULL,"
"	 \"group_id\" integer NOT NULL,"
"	 \"permission_id\" integer NOT NULL,"
"	PRIMARY KEY(\"id\")"
");"
""
"BEGIN;"
"INSERT INTO \"group_permissions\" VALUES ('1', '1', '1');"
"INSERT INTO \"group_permissions\" VALUES ('2', '1', '2');"
"INSERT INTO \"group_permissions\" VALUES ('3', '1', '3');"
"INSERT INTO \"group_permissions\" VALUES ('4', '1', '4');"
"INSERT INTO \"group_permissions\" VALUES ('5', '1', '5');"
"INSERT INTO \"group_permissions\" VALUES ('6', '1', '6');"
"INSERT INTO \"group_permissions\" VALUES ('7', '1', '7');"
"INSERT INTO \"group_permissions\" VALUES ('8', '1', '8');"
"INSERT INTO \"group_permissions\" VALUES ('9', '1', '9');"
"INSERT INTO \"group_permissions\" VALUES ('10', '1', '10');"
"INSERT INTO \"group_permissions\" VALUES ('11', '1', '11');"
"INSERT INTO \"group_permissions\" VALUES ('12', '1', '12');"
"INSERT INTO \"group_permissions\" VALUES ('13', '1', '13');"
"INSERT INTO \"group_permissions\" VALUES ('14', '4', '14');"
"INSERT INTO \"group_permissions\" VALUES ('15', '1', '15');"
"INSERT INTO \"group_permissions\" VALUES ('16', '1', '16');"
"INSERT INTO \"group_permissions\" VALUES ('17', '1', '17');"
"INSERT INTO \"group_permissions\" VALUES ('18', '1', '18');"
"INSERT INTO \"group_permissions\" VALUES ('19', '1', '19');"
"INSERT INTO \"group_permissions\" VALUES ('20', '1', '20');"
"INSERT INTO \"group_permissions\" VALUES ('21', '2', '1');"
"INSERT INTO \"group_permissions\" VALUES ('22', '2', '2');"
"INSERT INTO \"group_permissions\" VALUES ('23', '2', '3');"
"INSERT INTO \"group_permissions\" VALUES ('24', '2', '4');"
"INSERT INTO \"group_permissions\" VALUES ('25', '2', '5');"
"INSERT INTO \"group_permissions\" VALUES ('26', '2', '6');"
"INSERT INTO \"group_permissions\" VALUES ('27', '2', '7');"
"INSERT INTO \"group_permissions\" VALUES ('28', '2', '8');"
"INSERT INTO \"group_permissions\" VALUES ('29', '2', '9');"
"INSERT INTO \"group_permissions\" VALUES ('30', '2', '10');"
"INSERT INTO \"group_permissions\" VALUES ('31', '2', '11');"
"INSERT INTO \"group_permissions\" VALUES ('32', '2', '13');"
"INSERT INTO \"group_permissions\" VALUES ('33', '2', '14');"
"INSERT INTO \"group_permissions\" VALUES ('34', '2', '15');"
"INSERT INTO \"group_permissions\" VALUES ('35', '2', '16');"
"INSERT INTO \"group_permissions\" VALUES ('36', '2', '17');"
"INSERT INTO \"group_permissions\" VALUES ('37', '2', '18');"
"INSERT INTO \"group_permissions\" VALUES ('38', '2', '19');"
"INSERT INTO \"group_permissions\" VALUES ('39', '2', '20');"
"INSERT INTO \"group_permissions\" VALUES ('40', '3', '1');"
"INSERT INTO \"group_permissions\" VALUES ('41', '3', '3');"
"INSERT INTO \"group_permissions\" VALUES ('42', '3', '6');"
"INSERT INTO \"group_permissions\" VALUES ('43', '3', '9');"
"INSERT INTO \"group_permissions\" VALUES ('44', '3', '11');"
"INSERT INTO \"group_permissions\" VALUES ('45', '3', '13');"
"INSERT INTO \"group_permissions\" VALUES ('46', '3', '14');"
"INSERT INTO \"group_permissions\" VALUES ('47', '3', '15');"
"INSERT INTO \"group_permissions\" VALUES ('48', '3', '17');"
"INSERT INTO \"group_permissions\" VALUES ('49', '3', '18');"
"INSERT INTO \"group_permissions\" VALUES ('50', '3', '19');"
"INSERT INTO \"group_permissions\" VALUES ('51', '3', '20');"
"INSERT INTO \"group_permissions\" VALUES ('52', '4', '1');"
"INSERT INTO \"group_permissions\" VALUES ('53', '4', '22');"
"INSERT INTO \"group_permissions\" VALUES ('54', '4', '8');"
"INSERT INTO \"group_permissions\" VALUES ('55', '4', '3');"
"INSERT INTO \"group_permissions\" VALUES ('56', '4', '21');"
"INSERT INTO \"group_permissions\" VALUES ('57', '4', '14');"
"INSERT INTO \"group_permissions\" VALUES ('58', '4', '9');"
"INSERT INTO \"group_permissions\" VALUES ('59', '4', '13');"
"INSERT INTO \"group_permissions\" VALUES ('60', '5', '22');"
"INSERT INTO \"group_permissions\" VALUES ('61', '5', '8');"
"INSERT INTO \"group_permissions\" VALUES ('62', '5', '3');"
"INSERT INTO \"group_permissions\" VALUES ('63', '5', '14');"
"INSERT INTO \"group_permissions\" VALUES ('64', '1', '21');"
"INSERT INTO \"group_permissions\" VALUES ('65', '1', '22');"
"INSERT INTO \"group_permissions\" VALUES ('66', '2', '21');"
"INSERT INTO \"group_permissions\" VALUES ('67', '2', '22');"
"INSERT INTO \"group_permissions\" VALUES ('68', '3', '21');"
"INSERT INTO \"group_permissions\" VALUES ('69', '3', '22');"
"COMMIT;"
""
"DROP TABLE IF EXISTS \"groups\";"
"CREATE TABLE \"groups\" ("
"	 \"id\" integer NOT NULL,"
"	 \"group_name\" text NOT NULL,"
"	PRIMARY KEY(\"id\")"
");"
""
"BEGIN;"
"INSERT INTO \"groups\" VALUES ('1', 'Owner');"
"INSERT INTO \"groups\" VALUES ('2', 'Leader');"
"INSERT INTO \"groups\" VALUES ('3', 'Member');"
"INSERT INTO \"groups\" VALUES ('4', 'Regular');"
"INSERT INTO \"groups\" VALUES ('5', 'Player');"
"COMMIT;"
""
"DROP TABLE IF EXISTS \"lastlog\";"
"CREATE TABLE \"lastlog\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"last_log\" integer NOT NULL"
");"
""
"DROP TABLE IF EXISTS \"options\";"
"CREATE TABLE \"options\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"key\" text NOT NULL,"
"	 \"value\" text NOT NULL"
");"
""
"BEGIN;"
"INSERT INTO \"options\" VALUES ('1', 'welcome_msg', '^2Welcome to the ^1real world!');"
"INSERT INTO \"options\" VALUES ('2', 'welcome_player', '^2Welcome ^1%s ^2to in our arena');"
"INSERT INTO \"options\" VALUES ('3', 'not_allowed', '^2%s ^1is not allowed to use the \"^2%s\" command!');"
"COMMIT;"
""
"DROP TABLE IF EXISTS \"permissions\";"
"CREATE TABLE \"permissions\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"permission\" integer NOT NULL,"
"	 \"permission_name\" text NOT NULL"
");"
""
"BEGIN;"
"INSERT INTO \"permissions\" VALUES ('1', '!admincheck', 'Admincheck');"
"INSERT INTO \"permissions\" VALUES ('2', '!ban', 'ban');"
"INSERT INTO \"permissions\" VALUES ('3', '!cmd', 'cmd');"
"INSERT INTO \"permissions\" VALUES ('4', '!defaultmap', 'default map');"
"INSERT INTO \"permissions\" VALUES ('5', '!groups', 'groups');"
"INSERT INTO \"permissions\" VALUES ('6', '!kick', 'kick');"
"INSERT INTO \"permissions\" VALUES ('7', '!map', 'map');"
"INSERT INTO \"permissions\" VALUES ('8', '!nextmap', 'nextmap');"
"INSERT INTO \"permissions\" VALUES ('9', '!pl', 'pl');"
"INSERT INTO \"permissions\" VALUES ('10', '!playlist', 'playlist');"
"INSERT INTO \"permissions\" VALUES ('11', '!rank', 'rank');"
"INSERT INTO \"permissions\" VALUES ('12', '!rcon', 'rcon');"
"INSERT INTO \"permissions\" VALUES ('13', '!reserved', 'reserved');"
"INSERT INTO \"permissions\" VALUES ('14', '!rules', 'rules');"
"INSERT INTO \"permissions\" VALUES ('15', '!say', 'say');"
"INSERT INTO \"permissions\" VALUES ('16', '!setgroup', 'set group');"
"INSERT INTO \"permissions\" VALUES ('17', '!stats', 'stats');"
"INSERT INTO \"permissions\" VALUES ('18', '!tempban', 'temp ban');"
"INSERT INTO \"permissions\" VALUES ('19', '!top', 'top');"
"INSERT INTO \"permissions\" VALUES ('20', '!uptime', 'uptime');"
"INSERT INTO \"permissions\" VALUES ('21', '!warn', 'warn');"
"INSERT INTO \"permissions\" VALUES ('22', '!me', 'me');"
"COMMIT;"
""
"DROP TABLE IF EXISTS \"rotate_message\";"
"CREATE TABLE \"rotate_message\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"message\" text NOT NULL"
");"
""
"DROP TABLE IF EXISTS \"rules_message\";"
"CREATE TABLE \"rules_message\" ("
"	 \"id\" integer NOT NULL,"
"	 \"rule_message\" text NOT NULL,"
"	PRIMARY KEY(\"id\")"
");"
""
"DROP TABLE IF EXISTS \"user\";"
"CREATE TABLE \"user\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"playerid\" integer NOT NULL,"
"	 \"crdate\" integer NOT NULL,"
"	 \"nickname\" text NOT NULL,"
"	 \"ip\" text,"
"	 \"first_join\" integer NOT NULL,"
"	 \"last_seen\" integer"
");"
""
"DROP TABLE IF EXISTS \"user_groups\";"
"CREATE TABLE \"user_groups\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"group_id\" integer NOT NULL,"
"	 \"user_id\" integer NOT NULL"
");"
""
"DROP TABLE IF EXISTS \"user_stats\";"
"CREATE TABLE \"user_stats\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"playerid\" integer NOT NULL,"
"	 \"kick_count\" integer DEFAULT '0',"
"	 \"ban_count\" integer DEFAULT '0',"
"	 \"tempban_count\" integer DEFAULT '0',"
"	 \"kill_count\" integer DEFAULT '0',"
"	 \"death_count\" integer DEFAULT '0',"
"	 \"teamkill_count\" integer DEFAULT '0'"
");"
""
"DROP TABLE IF EXISTS \"user_stats_weapon\";"
"CREATE TABLE \"user_stats_weapon\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"playerid\" integer NOT NULL,"
"	 \"killed_player\" integer NOT NULL,"
"	 \"weapon_id\" integer NOT NULL,"
"	 \"attachment_id_first\" integer DEFAULT '0',"
"	 \"attachment_id_second\" integer DEFAULT '0',"
"	 \"hitbox\" integer NOT NULL,"
"	 \"team\" integer NOT NULL,"
"	 \"enemy_team\" integer NOT NULL,"
"	 \"damage\" integer NOT NULL"
");"
""
"DROP TABLE IF EXISTS \"word_filter\";"
"CREATE TABLE \"word_filter\" ("
"	 \"id\" integer NOT NULL,"
"	 \"phrase\" text NOT NULL,"
"	 \"exact\" integer NOT NULL,"
"	PRIMARY KEY(\"id\")"
");"
""
"DROP TABLE IF EXISTS \"weapon\";"
"CREATE TABLE \"weapon\" ("
"	 \"id\" integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
"	 \"weapon_name\" text NOT NULL,"
"	 \"is_allowed\" integer NOT NULL DEFAULT '1'"
");"
""
"BEGIN;"
"INSERT INTO \"weapon\" VALUES ('1', 'MP5k', '1');"
"INSERT INTO \"weapon\" VALUES ('2', 'Skorpion', '1');"
"INSERT INTO \"weapon\" VALUES ('3', 'MAC11', '1');"
"INSERT INTO \"weapon\" VALUES ('4', 'Ak74u', '1');"
"INSERT INTO \"weapon\" VALUES ('5', 'Uzi', '1');"
"INSERT INTO \"weapon\" VALUES ('6', 'PM63', '1');"
"INSERT INTO \"weapon\" VALUES ('7', 'MPL', '1');"
"INSERT INTO \"weapon\" VALUES ('8', 'Spectre', '1');"
"INSERT INTO \"weapon\" VALUES ('9', 'Kiparis', '1');"
"INSERT INTO \"weapon\" VALUES ('10', 'M16', '1');"
"INSERT INTO \"weapon\" VALUES ('11', 'Enfield', '1');"
"INSERT INTO \"weapon\" VALUES ('12', 'M14', '1');"
"INSERT INTO \"weapon\" VALUES ('13', 'Famas', '1');"
"INSERT INTO \"weapon\" VALUES ('14', 'Galil', '1');"
"INSERT INTO \"weapon\" VALUES ('15', 'AUG', '1');"
"INSERT INTO \"weapon\" VALUES ('16', 'FN-FAL', '1');"
"INSERT INTO \"weapon\" VALUES ('17', 'Ak47', '1');"
"INSERT INTO \"weapon\" VALUES ('18', 'Commando', '1');"
"INSERT INTO \"weapon\" VALUES ('19', 'G11', '1');"
"INSERT INTO \"weapon\" VALUES ('20', 'Olympia', '1');"
"INSERT INTO \"weapon\" VALUES ('21', 'Stakeout', '1');"
"INSERT INTO \"weapon\" VALUES ('22', 'Spas', '1');"
"INSERT INTO \"weapon\" VALUES ('23', 'HS10', '1');"
"INSERT INTO \"weapon\" VALUES ('24', 'Hk21', '1');"
"INSERT INTO \"weapon\" VALUES ('25', 'RPK', '1');"
"INSERT INTO \"weapon\" VALUES ('26', 'M60', '1');"
"INSERT INTO \"weapon\" VALUES ('27', 'Stoner', '1');"
"INSERT INTO \"weapon\" VALUES ('28', 'Dragunov', '1');"
"INSERT INTO \"weapon\" VALUES ('29', 'WA2000', '1');"
"INSERT INTO \"weapon\" VALUES ('30', 'L96A1', '1');"
"INSERT INTO \"weapon\" VALUES ('31', 'PSG1', '1');"
"INSERT INTO \"weapon\" VALUES ('32', 'ASP', '1');"
"INSERT INTO \"weapon\" VALUES ('33', 'M1911', '1');"
"INSERT INTO \"weapon\" VALUES ('34', 'Makarov', '1');"
"INSERT INTO \"weapon\" VALUES ('35', 'Python', '1');"
"INSERT INTO \"weapon\" VALUES ('36', 'CZ75', '1');"
"INSERT INTO \"weapon\" VALUES ('37', 'LAW', '1');"
"INSERT INTO \"weapon\" VALUES ('38', 'RPG', '1');"
"INSERT INTO \"weapon\" VALUES ('39', 'Strela', '1');"
"INSERT INTO \"weapon\" VALUES ('40', 'China Lake', '1');"
"INSERT INTO \"weapon\" VALUES ('41', 'Crossbow', '1');"
"INSERT INTO \"weapon\" VALUES ('42', 'Crossbow', '1');"
"INSERT INTO \"weapon\" VALUES ('43', 'Grenade Launcher', '1');"
"INSERT INTO \"weapon\" VALUES ('44', 'Masterkey', '1');"
"INSERT INTO \"weapon\" VALUES ('45', 'Flamethrower', '1');"
"INSERT INTO \"weapon\" VALUES ('46', 'Dual Wield', '1');"
"INSERT INTO \"weapon\" VALUES ('47', 'Dual Mags', '1');"
"INSERT INTO \"weapon\" VALUES ('48', 'Extended Mags', '1');"
"INSERT INTO \"weapon\" VALUES ('49', 'Silencer', '1');"
"INSERT INTO \"weapon\" VALUES ('50', 'Red Dot Sight', '1');"
"INSERT INTO \"weapon\" VALUES ('51', 'ACOG Scope', '1');"
"INSERT INTO \"weapon\" VALUES ('52', 'Reflex Sight', '1');"
"INSERT INTO \"weapon\" VALUES ('53', 'Low Power Scope', '1');"
"INSERT INTO \"weapon\" VALUES ('54', 'Variable Zoom', '1');"
"INSERT INTO \"weapon\" VALUES ('55', 'Full Auto Pistols', '1');"
"INSERT INTO \"weapon\" VALUES ('56', 'Speed Reloader', '1');"
"INSERT INTO \"weapon\" VALUES ('57', 'Snub Nose', '1');"
"INSERT INTO \"weapon\" VALUES ('58', 'Grip', '1');"
"INSERT INTO \"weapon\" VALUES ('59', 'Upgraded Iron Sights', '1');"
"INSERT INTO \"weapon\" VALUES ('60', 'IR Scope', '1');"
"INSERT INTO \"weapon\" VALUES ('61', 'Rapid Fire', '1');"
"INSERT INTO \"weapon\" VALUES ('62', 'RCXD', '1');"
"INSERT INTO \"weapon\" VALUES ('63', 'Napalm Strike', '1');"
"INSERT INTO \"weapon\" VALUES ('64', 'Sentry Gun', '1');"
"INSERT INTO \"weapon\" VALUES ('65', 'Mortar Team', '1');"
"INSERT INTO \"weapon\" VALUES ('66', 'Attack Helicopter', '1');"
"INSERT INTO \"weapon\" VALUES ('67', 'Valkyrie Rockets', '1');"
"INSERT INTO \"weapon\" VALUES ('68', 'Rolling Thunder', '1');"
"INSERT INTO \"weapon\" VALUES ('69', 'Chopper Gunner', '1');"
"INSERT INTO \"weapon\" VALUES ('70', 'Gunship', '1');"
"INSERT INTO \"weapon\" VALUES ('71', 'Attack Dogs', '1');"
"INSERT INTO \"weapon\" VALUES ('72', 'Grim Reaper', '1');"
"INSERT INTO \"weapon\" VALUES ('73', 'Death Machine', '1');"
"INSERT INTO \"weapon\" VALUES ('74', 'Knife', '1');"
"INSERT INTO \"weapon\" VALUES ('75', 'Frag Grenade', '1');"
"INSERT INTO \"weapon\" VALUES ('76', 'Semtex', '1');"
"INSERT INTO \"weapon\" VALUES ('77', 'Tomahawk', '1');"
"INSERT INTO \"weapon\" VALUES ('78', 'Willy Pete', '1');"
"INSERT INTO \"weapon\" VALUES ('79', 'Flashbang', '1');"
"INSERT INTO \"weapon\" VALUES ('80', 'Concussion Grenade', '1');"
"INSERT INTO \"weapon\" VALUES ('81', 'Nova gas', '1');"
"INSERT INTO \"weapon\" VALUES ('82', 'Decoy Grenade', '1');"
"INSERT INTO \"weapon\" VALUES ('83', 'Claymore', '1');"
"INSERT INTO \"weapon\" VALUES ('84', 'C4', '1');"
"INSERT INTO \"lastlog\" VALUES ('1', '0');"
"COMMIT;"
""
 "CREATE UNIQUE INDEX \"plididx\" ON \"user\" (playerid);"
 "CREATE INDEX \"fjidx\" ON \"user\" (first_join);"
 "CREATE INDEX \"usernmidx\" ON \"user\" (nickname);"
 "CREATE INDEX \"grppidx\" ON \"group_permissions\" (group_id);"
 "CREATE INDEX \"peridx\" ON \"group_permissions\" (permission_id);"
 "CREATE INDEX \"keyidx\" ON \"options\" (value);"
 "CREATE INDEX \"cmdix\" ON \"permissions\" (permission);"
 "CREATE INDEX \"grpidx\" ON \"user_groups\" (group_id);"
 "CREATE UNIQUE INDEX \"plidsidx\" ON \"user_stats\" (playerid);"
 "CREATE INDEX \"plysididx\" ON \"user_stats_weapon\" (playerid);"
;
/*
 "CREATE INDEX \"ckickidx\" ON \"user_stats\" (kick_count);"
 "CREATE INDEX \"cbanidx\" ON \"user_stats\" (ban_count);"
 "CREATE INDEX \"ctempbanidx\" ON \"user_stats\" (tempban_count);"
 "CREATE INDEX \"ckillctidx\" ON \"user_stats\" (kill_count);"
 "CREATE INDEX \"cdeathcidx\" ON \"user_stats\" (death_count);"
 "CREATE INDEX \"cteamkillcidx\" ON \"user_stats\" (teamkill_count);"
 "CREATE INDEX \"killpidx\" ON \"user_stats_weapon\" (killed_player);"
 "CREATE INDEX \"wpidx\" ON \"user_stats_weapon\" (weapon_id);"
 "CREATE INDEX \"attchoneidx\" ON \"user_stats_weapon\" (attachment_id_first);"
 "CREATE INDEX \"attchtwoidx\" ON \"user_stats_weapon\" (attachment_id_second);"
 "CREATE INDEX \"teamidx\" ON \"user_stats_weapon\" (team);"
 "CREATE INDEX \"enmtidx\" ON \"user_stats_weapon\" (enemy_team);"
 "CREATE INDEX \"dmgidx\" ON \"user_stats_weapon\" (damage);"
 "CREATE INDEX \"wpnameidx\" ON \"weapon\" (weapon_name);"
*/
#endif
