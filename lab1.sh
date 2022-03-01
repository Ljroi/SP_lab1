#!/bin/bash

echo "Гриценко АА"
echo "Получение UID и групп пользователя"

while true
do
	echo "Введите имя пользователя?"
	read user_name

	if grep $user_name /etc/passwd
	then
		id $user_name
		id -u $user_name
		id -g $user_name
	else
	echo "Пользователя с таким именем не существует"
	fi
	echo "Хотите повторно проверить пользователя? (Y/N)"
	read ans
	if [[ "$ans" =~ ^([yY][eE][sS]|[yY])$ ]]
	then
	echo "Давайте продолжим"
	else break
	fi
done
