cleos system newaccount eosio bp.info11111 EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV --stake-net "10.0000 EOS" --stake-cpu "10.0000 EOS" --buy-ram "10.0000 EOS"
cleos set contract bp.info11111 $EOS_BUILD_DIR/contracts/bp_info/ -p bp.info11111

cleos set account permission inita1111111 active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bp.info11111","permission":"eosio.code"},"weight":1}]}' owner -p inita1111111
cleos set account permission initb1111111 active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bp.info11111","permission":"eosio.code"},"weight":1}]}' owner -p initb1111111


cleos push action bp.info11111 setinfo '{"producer":"inita1111111", "organization":"eosio.sg", "social_media_url":"http://www.eosio.sg", "producer_logo_url": "http://www.eosio.sg", "donate": "1.0000 EOS"}' -p inita1111111

cleos push action bp.info11111 setinfo '{"producer":"initb1111111", "organization":"eosio.g", "social_media_url":"http://ww.eosio.sg", "producer_logo_url": "http://ww.eosio.sg", "donate": "1.0000 EOS"}' -p initb1111111

cleos push action bp.info11111 setinfo '{"producer":"initb1111111", "organization":"eosio", "social_media_url":"http://ww.eosio.sg", "producer_logo_url": "http://w.sg", "donate": "20.0000 EOS"}' -p initb1111111

cleos get table bp.info11111 inita1111111 bpinfo
cleos get table bp.info11111 initb1111111 bpinfo

