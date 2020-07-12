#!/bin/bash

for assetstatus in "`ps -ef | grep asset-server | awk '{print $2}'| sed -n '1'p`"
do
kill -9 $assetstaus;
echo "asset shutdown [ok]"
done
