#!/bin/sh
while true

do
ps -ef | grep "$PWD/auto_run.sh" | grep -v "grep"
if [ "$?" -eq 1 ]
then
/home/cc/zhuw/lingp/pythia8243/examples/ppdata/python.sh #启动应用，修改成自己
的启动应用脚本或命令
echo "process has been restarted!"
else
echo "process already started!"
fi
sleep 100
done

