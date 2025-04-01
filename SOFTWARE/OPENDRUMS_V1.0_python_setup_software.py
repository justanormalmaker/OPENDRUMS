import serial.tools.list_ports
import time
import tkinter as tk
from tkinter import ttk

def get_serial_ports():
    ports = [port.device for port in serial.tools.list_ports.comports()]
    return ports if ports else ["No ports found"]

def send_to_arduino(port, baudrate, data):
    try:
        with serial.Serial(port, baudrate, timeout=1) as ser:
            time.sleep(2)  # Aspetta che la connessione sia stabile
            ser.write(f"{data}\n".encode())
            print(f"Send: {data}")
            result_label.config(text=f"Send {data} file at {port}", foreground="green")
    except Exception as e:
        result_label.config(text=f"Error: {e}", foreground="red")

def send_manual_count():
    try:
        file_count = int(file_count_var.get())
        arduino_port = port_var.get()
        baudrate = int(baudrate_var.get())
        send_to_arduino(arduino_port, baudrate, file_count)
    except ValueError:
        result_label.config(text="Insert a correct value.", foreground="red")

# Creazione dell'interfaccia grafica
root = tk.Tk()
root.title("OPENDRUMS Setup")
root.geometry("400x250")
root.resizable(False, False)
root.configure(bg="#f0f0f0")

file_count_var = tk.StringVar()
port_var = tk.StringVar(value="COM3")
baudrate_var = tk.StringVar(value="115200")

frame = ttk.Frame(root, padding=20)
frame.pack(fill="both", expand=True)

style = ttk.Style()
style.configure("TButton", font=("Arial", 10), padding=5)
style.configure("TLabel", font=("Arial", 10))
style.configure("TEntry", font=("Arial", 10))

# Numero di file
ttk.Label(frame, text="File number:").grid(row=0, column=0, sticky="w", pady=5)
ttk.Entry(frame, textvariable=file_count_var, width=10).grid(row=0, column=1, pady=5)

# Porta Arduino
ttk.Label(frame, text="OPENDRUMS port:").grid(row=1, column=0, sticky="w", pady=5)
ports = get_serial_ports()
port_dropdown = ttk.Combobox(frame, textvariable=port_var, values=ports, state="readonly")
port_dropdown.grid(row=1, column=1, pady=5)
if ports:
    port_var.set(ports[0])  # Imposta il primo valore disponibile

# Pulsante di invio
send_button = ttk.Button(frame, text="Send", command=send_manual_count)
send_button.grid(row=3, column=1, pady=10)

# Etichetta di stato
result_label = ttk.Label(frame, text="", font=("Arial", 10, "bold"))
result_label.grid(row=4, column=0, columnspan=2, pady=10)

root.mainloop()
