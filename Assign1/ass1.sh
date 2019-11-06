var=1
while [ $var -eq 1 ]
do
	echo "1. Create Address Book"
	echo "2. View"
	echo "3. Insert"
	echo "4. Modify"
	echo "5. Delete"
	echo "6. Exit"
	read choice
	case $choice in
		1)	if [ -e record.txt ]
			then
				echo "File is already present"
			else
				touch record.txt
			fi;;
		
		2)  echo -ne "1. View whole address book\n2. View a specific record"
			read ch
			if [ $ch -eq 1 ]
			then
				if [ -s record.txt ]
				then
					echo -ne "Reg no	 Name		Mobile		Address		Year"
					echo ""
					cat record.txt
					echo ""
				else
					echo "No data found in the file"
				fi
			else
				echo -ne "Enter the registration no \n" 
	    		read rgg
	    		echo -ne "\n"
 				grep -i -ne " $rgg " record.txt > temp.txt
 				if [[ -s temp.txt ]] 
 					then 
 					cat temp.txt
 				else
 				echo "No data found with the particular reg no"
 				fi
			fi;;
		
		3) 	read -p "REG_NO" reg
		   	read -p "Name" name
		   	read -p "Address" as
		   	read -p "Mobile Number" mob
			read -p "year" yr
			
			echo -ne " $reg \t $name \t\t$mob \t$as \t$yr \n">>record.txt;;
		
		4)	if [ -s record.txt ]
			then
				read -p "Enter the reg no " reg
				grep -i -n "^$reg" record.txt > ab.txt
				line=$(head -c 1 ab.txt)
				echo "Old data"
				cat ab.txt 
				echo -ne "\n Enter previous data "
				read d1
				echo "Enter new data"
				read d2
				sed -i -e "$line s/$d1/$d2/g" record.txt
			else
				echo "The file is empty"
			fi;;
			
		5)	if [ -s record.txt ]
			then
				echo "Enter the reg no "
				read reg
				reg=" ${reg} "
				sed -i -e "/$reg/d" record.txt
			else
				echo "The file is already empty"
			fi;;
	esac
 
	echo "Do you want to continue or not?"
	echo "1.Continue    0.Exit"
	read var
done
