//
// Created by Yu Yang Zhang on 6/5/18.
//

#ifndef EOSIO_ACCOUNT_DETAIL_HPP
#define EOSIO_ACCOUNT_DETAIL_HPP

#include <eosiolib/eosio.hpp>
#include <eosio.system/eosio.system.hpp>
#include <string>
#include <eosio.token/eosio.token.hpp>


using namespace eosio;
using namespace std;

class eosio_account_info : public eosio::contract {
public:
	eosio_account_info(account_name self) : contract(self) {};

private:
	//@abi table
	struct account_info {
		account_name account;
		std::string avatar;
		std::string full_image;
		std::string website;
		std::string facebook;
		std::string twitter;
		std::string medium;
		std::string steemit;
		std::string telegram;
		std::string github;
		std::string organization;
		asset donate = asset(0);

		auto primary_key() const { return account; }

		EOSLIB_SERIALIZE(account_info, (account)(avatar)(full_image)(website)(facebook)(twitter)(medium)(steemit)(telegram)(github)(organization)(donate));
	};

	typedef eosio::multi_index<N(accountinfo), account_info> accountinfo;

public:
	//@abi action
	void setinfo(account_name account, string &avatar, string &full_image, string &website, string &facebook,
				 string &twitter, string &medium, string &steemit, string &telegram, string &github,
				 string &organization, asset donate);

};


#endif //EOSIO_ACCOUNT_DETAIL_HPP
