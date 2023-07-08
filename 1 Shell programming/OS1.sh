#!/bin/sh

# Run the while loop infinitly

echo "\nWELCOME TO THE ADDRESS BOOK\n"

while(true) do
	# Print the Menu
	echo "\n**********************************"
	echo "|            MENU                |"
	echo "**********************************"
	echo "| 1) Create Address Book         |"
	echo "| 2) Insert a Record             |"
	echo "| 3) View Address Book           |"
    	echo "| 4) Search a Record             |"
	echo "| 5) Delete a Record             |"
	echo "| 6) Modify a Record             |"
	echo "| 7) Exit                        |" 
	echo "**********************************"
	echo "\n Enter your choice - \c"
	read choice

	# Switch case
	case "$choice" in
	1) 
		echo "\n Creating the address book"

		# Read the filename
		echo "\n Enter name of the new file or existing file - \c"
		read filename
		
		touch $filename
			echo "\n File with name $filename was created successfully"
	;;


	2) 
		echo "\n Inserting a new Record"

		# Take input for new record
		echo "\n Enter the Name - \c"
		# Validation for name
			read name

		echo "\n Enter the Address - \c"
		# Validation for address
			read address
			

		echo "\n Enter the Phone Number - \c"
		# Validation for phone number
			read phone
			
		# Write into file
		echo "$name\t$address\t$phone" >> $filename
		echo "\n Record inserted successfully"
	;;

	3) 
		echo "\nThe Address book is shown below"
		echo "\nNAME\tADDRESS\tPHONE NO" 
		# Show the sorted output
		cat $filename |	sort
		 
	;;

	4) 
		echo "\n Search a Record"
		echo "\n Enter the phone number of the record to be searched- \c"
		# Validation for phone number
		
			read sphone
			
		trecord=$(grep -w -i "$sphone" $filename)
		len=$(echo -n $trecord | wc -m)
		if test $len -eq 0; then
			echo "\n No record found"
		else
			echo "\nNAME\tADDRESS\tPHONE NO"
			echo "$trecord"	
		fi
	;;


	5) 
		echo "\n Deleting a Record"

		# Take the phone number to be deleted
		echo "\n Enter the Phone Number - \c"
		# Validation for phone number
			read sphone
			
		grep -v -i "$sphone" $filename > temp
		mv temp $filename
		echo "\n Record deleted successfully"
	;;
		

	6) 
		echo "\n Modify a Record"

		# Take the phone number to be modified		
		echo "\n Enter the phone number of the record to be modified- \c"
		# Validation for phone number
			read mphone
		echo	
		# Fetch the whole record from  the file
		trecord=$(grep -w -i "$mphone" $filename)
		echo " $trecord"

		cnt=0
		for i in $trecord 
		do 
			cnt=`expr $cnt + 1`
			if test $cnt -eq 1; 
			then
				tname=$i
			elif test $cnt -eq 2; 
			then
				taddress=$i
			elif test $cnt -eq 3; 
			then
				tphone=$i
			fi 
		done

		# Take input for modified record
		echo "\n What would you like to modify"
		echo " 1. Name \n 2. Address \n 3. Phone Number \n Please Enter - \c"
		read c
		# Switch case
		case "$c" in
		1) 
			echo "\n Enter the new Name - \c"
			# Validation for name
				read tname
				
		;;
		2)
			echo "\n Enter the new Address - \c"
			# Validation for address
				read taddress
				
		;;
		3)
			echo "\n Enter the new Phone Number - \c"
			# Validation for phone number
				read tphone
				
		;;
		esac
		# Replace the record in place
		sed "s/$trecord/$tname\t$taddress\t$tphone/g" $filename > temp
		mv temp $filename
		echo "\n Record Modified successfully"
	;;

	7) 	echo "\n Exiting program.."
		exit
	
	;;
	*) echo "\n Invalid option"
	;;
	esac
done
