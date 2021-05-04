from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from tkinter import *
import sys

browser = None

def login_to_carleton(username, password):
    browser.find_element_by_id("loginLink").click()
    WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='divLoginOptions']/div[2]/div[2]/div/button"))).click()

    username_form = browser.find_element_by_id("userNameInput")
    password_form = browser.find_element_by_id("passwordInput")

    username_form.send_keys(username)
    password_form.send_keys(password)

    WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='submitButton']"))).click()

def book_session(day, time):
    day = day.lower()
    if(day == "monday"):
        WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='list-group']/div[1]/div"))).click()
    elif(day == "tuesday"):
        WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='list-group']/div[2]/div"))).click()
    elif(day == "wednesday"):
        WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='list-group']/div[3]/div"))).click()
    elif(day == "thursday"):
        WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='list-group']/div[4]/div"))).click()
    elif(day == "friday"):
        WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='list-group']/div[5]/div"))).click()
    elif(day == "saturday"):
        WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='list-group']/div[6]/div"))).click()
    elif(day == "sunday"):
        WebDriverWait(browser, 20).until(EC.element_to_be_clickable((By.XPATH, "//*[@id='list-group']/div[7]/div"))).click()
    else:
        print("Invalid Input for Day")


def open_browser():
    global browser
    browser = webdriver.Chrome()
    browser.get('https://rec.carleton.ca/Program/GetProducts?classification=d17305dd-be9c-4889-a554-336cb4fb78e0&category=38f6aaac-d0bd-448c-9069-6523b8bb73d9')

def main(argv):
    open_browser();
    login_to_carleton(argv[0], argv[1])
    book_session(argv[2], argv[3])


main(sys.argv[1:])
