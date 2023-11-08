
#Info arquitectura
uname -a #Arquitectura del SO
grep "physical id" /proc/cpuinfo | wc -l #Núcleos físicos
grep processor /proc/cpuinfo | wc -l #Núcleos virtuales

#RAM
free --mega | awk '$1 == "Mem:" {print $3}' #RAM Columna used
free --mega | awk '$1 == "Mem:" {print $2}' #RAM Columna total
free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}' #Porcentaje de memoria usada

#HDD
df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} END {print memory_use}' #Memoria del disco ocupada
df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_result += $2} END {printf("%.0fGb\n", memory_result/1024)}' #Memoria total disco
df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100}' #Porcentaje de uso de memoria

#Porcentaje uso CPU
vmstat 1 4 | tail -1 | awk '{print %15}' #Intervalo de 4 segundos que muestra solo el último (% inactivo de uso de CPU)
who -b | awk '$1 == "system" {print $3 " " $4}' #Muestra la hora del último arranque del sistema
if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi #Determina si la máquina virtual esta ejecutándose
ss -ta | grep ESTAB | wc -l #Conexiones TCP establecidas
users | wc -w #Usuarios que hay
ip link | grep "link/ether" | awk '{print $2}' #Printar dirección mac
