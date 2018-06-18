//
// Created by Yu Yang Zhang on 6/5/18.
//

#include "account_detail.hpp"
#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/symbol.hpp>


using eosio::asset;

//@abi action
void eosio_account_info::setinfo(account_name account, string &avatar, string &full_image, string &website,
								 string &facebook, string &twitter, string &medium, string &steemit,
								 string &telegram, string &github, string &organization, asset donate) {
	require_auth(account);
	eosio::print("account is ", name{account}, "\n");

	eosio_account_info::accountinfo accountinfo(_self, account);

	auto itr = accountinfo.find(account);

	if (itr == accountinfo.end()) {
		accountinfo.emplace(account, [&](auto &p) {
			p.account= account;
			p.avatar = avatar;
			p.full_image = full_image;
			p.website = website;
			p.facebook = facebook;
			p.twitter = twitter;
			p.medium = medium;
			p.steemit = steemit;
			p.telegram = telegram;
			p.github = github;
			p.organization = organization;
			p.donate = donate;
			print("new organization is ", p.organization, "\n");
			if (donate > asset(0)) {
				INLINE_ACTION_SENDER(eosio::token, transfer)(N(eosio.token), {account, N(active)},
															 {account, N(accountinfo1), donate,
															  std::string("change info donate fee")});
			}
		});
	} else {
		accountinfo.modify(itr, itr->account, [&](auto &p) {
			print("origin organization is ", p.organization, "\n");
			p.account= account;
			p.avatar = avatar;
			p.full_image = full_image;
			p.website = website;
			p.facebook = facebook;
			p.twitter = twitter;
			p.medium = medium;
			p.steemit = steemit;
			p.telegram = telegram;
			p.github = github;
			p.organization = organization;
			p.donate += donate;

			print("update organization is ", p.organization, "\n");
		});
		print("cost money for change the info, account is: ", account);
		if (donate > asset(0)) {
			INLINE_ACTION_SENDER(eosio::token, transfer)(N(eosio.token), {account, N(active)},
														 {account, N(accountinfo1), donate,
														  std::string("change info donate fee")});
		}
	}
}


EOSIO_ABI(eosio_account_info, (setinfo))