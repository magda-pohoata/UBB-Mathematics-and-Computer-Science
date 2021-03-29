package ctrl;

import Repository.CarFileRepo;
import Repository.RentalFileRepo;
import Service.CarRentalService;
import Service.ServiceException;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.KeyEvent;
import javafx.scene.text.*;
import model.*;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.List;
import java.util.Properties;
import java.util.stream.Collectors;

public class RentalCarsController {

    //for Cars
    @FXML
    private TextField manufacturerCarText,modelCarText,yearCarText,priceCarText,maxSpeedCarText;
    @FXML
    private Text carIDtext;
    @FXML
    private TableView<Car> carTab1Table;
    @FXML
    private Button addCar,deleteCar,updateCar,ClearCar;


    //for Rentals
    @FXML
    private TextField nameRenterText,daysRentalText,carIDRentalText,dateRentalText;
    @FXML
    private Text rentalIDText;
    @FXML
    private TableView<Rental> rentalTab2Table;
    @FXML
    private TableView<Car> carTab2Table;
    @FXML
    private Button addRental,deleteRental,updateRental,ClearRental;

    //for Filters
    @FXML
    private TextField fByManufacturerText,fByModelText,fUnderYearText,fCheaperPriceText,fByManufacturerAndModelText,fByCustomerText,fByDateText,fUnderNrDaysText,fDateByCustomerText,fCustomerByDateText;
    @FXML
    private Button fByManufacturer,fByModel,fUnderYear,fCheaperPrice,fByManufacturerAndModel,fByCustomer,fByDate,fUnderNrDays,fDateByCustomer,fCustomerByDate;
    @FXML
    private TableView<Rental> rentalTab3Table;
    @FXML
    private TableView<Car> carTab3Table;



    public RentalCarsController(){}

    private CarRentalService service;

    public void setService(CarRentalService service){
        this.service=service;
    }

    private boolean checkString(String s){ return s == null || s.isBlank() ? false : true;}

    @FXML
    public void initialize()
    {
        setService(getService());
        List<Car> carsTab1= service.getCarRepo().getAll().stream().collect(Collectors.toList());
        List<Rental> rentalTab2 =service.getRentalRepo().getAll().stream().collect(Collectors.toList());
        carTab1Table.getItems().addAll(carsTab1);
        carTab2Table.getItems().addAll(carsTab1);
        rentalTab2Table.getItems().addAll(rentalTab2);
    }

    @FXML
    private void displaySelectedCarTab1(MouseEvent mouseEvent){
        Car c=carTab1Table.getSelectionModel().getSelectedItem();
        showCarTab1(c);
    }

    @FXML
    private void displaySelectedCarTab2(MouseEvent mouseEvent){
        Car c=carTab2Table.getSelectionModel().getSelectedItem();

        showCarTab2(c);
    }

    public void clearFieldsTab1(){
        carIDtext.setText("");
        manufacturerCarText.setText("");
        modelCarText.setText("");
        maxSpeedCarText.setText("");
        yearCarText.setText("");
        priceCarText.setText("");
    }

    private void showCarTab1(Car newItem){
        if(newItem == null)
            clearFieldsTab1();
        else{
            carIDtext.setText(""+newItem.getID());
            manufacturerCarText.setText(""+newItem.getManufacturer());
            modelCarText.setText(""+newItem.getModel());
            maxSpeedCarText.setText(""+newItem.getMax_speed());
            yearCarText.setText(""+newItem.getYear());
            priceCarText.setText(""+newItem.getYear());
        }
    }
    private void showCarTab2(Car newItem){
        if(newItem == null)
            clearFieldsTab2();
        else{
            carIDRentalText.setText(""+newItem.getID());
        }
    }



    @FXML
    private void displaySelectedRentalTab2(MouseEvent mouseEvent){
        Rental r=rentalTab2Table.getSelectionModel().getSelectedItem();
        showRentalTab2(r);
    }

    private void showRentalTab2(Rental newItem){
        if(newItem == null)
            clearFieldsTab2();
        else{
            rentalIDText.setText(""+newItem.getID());
            nameRenterText.setText(""+newItem.getName());
            dateRentalText.setText(""+newItem.getDate());
            daysRentalText.setText(""+newItem.getNo_days());
            carIDRentalText.setText(""+newItem.getCarID());
        }
    }

    public void clearFieldsTab2(){
        rentalIDText.setText("");
        nameRenterText.setText("");
        dateRentalText.setText("");
        daysRentalText.setText("");
        carIDRentalText.setText("");
    }

    @FXML
    public void addCarHandler(ActionEvent actionEvent) {
        String manufacturer=manufacturerCarText.getText();
        String model=modelCarText.getText();
        String max_speed=maxSpeedCarText.getText();
        String year=yearCarText.getText();
        String price=priceCarText.getText();

        if (checkString(manufacturer)&&checkString(model)&&checkString(max_speed)&&checkString(year)&&checkString(price)){
            try {
                int max_speed1=Integer.parseInt(max_speed);
                int year1=Integer.parseInt(year);
                int price1=Integer.parseInt(price);
                int id = service.addCar(manufacturer, model, year1, price1, max_speed1);
                carIDtext.setText("" + id);
                carTab1Table.getItems().clear();
                carTab2Table.getItems().clear();
                List<Car> carsTab1= service.getCarRepo().getAll().stream().collect(Collectors.toList());
                carTab1Table.getItems().addAll(carsTab1);
                carTab2Table.getItems().addAll(carsTab1);
                showNotification("Car successfully added! ", Alert.AlertType.INFORMATION);
            }catch(ServiceException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }catch(NumberFormatException ex){
                showNotification("Please insert numbers where needed!", Alert.AlertType.ERROR);
                yearCarText.setText("");
                priceCarText.setText("");
                maxSpeedCarText.setText("");
                return;
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }

    @FXML
    public void updateCarHandler(ActionEvent actionEvent) {
        String ID=carIDtext.getText();
        String manufacturer=manufacturerCarText.getText();
        String model=modelCarText.getText();
        String max_speed=maxSpeedCarText.getText();
        String year=yearCarText.getText();
        String price=priceCarText.getText();

        if (checkString(ID)&&checkString(manufacturer)&&checkString(model)&&checkString(max_speed)&&checkString(year)&&checkString(price)){
            try {
                int carID=Integer.parseInt(ID);
                int max_speed1=Integer.parseInt(max_speed);
                int year1=Integer.parseInt(year);
                int price1=Integer.parseInt(price);
                Car c=new Car(carID,manufacturer, model, year1, price1,max_speed1);
                service.updateCar(c,carID);
                carTab1Table.getItems().clear();
                carTab2Table.getItems().clear();
                List<Car> carsTab1= service.getCarRepo().getAll().stream().collect(Collectors.toList());
                carTab1Table.getItems().addAll(carsTab1);
                carTab2Table.getItems().addAll(carsTab1);
                showNotification("Car successfully updated! ", Alert.AlertType.INFORMATION);
            }catch(ServiceException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }

    @FXML
    public void deleteCarHandler(ActionEvent actionEvent) {
        String idCar=carIDtext.getText();
        String manufacturer=manufacturerCarText.getText();
        String model=modelCarText.getText();
        String max_speed=maxSpeedCarText.getText();
        String year=yearCarText.getText();
        String price=priceCarText.getText();

        if (checkString(idCar)&&checkString(manufacturer)&&checkString(model)&&checkString(max_speed)&&checkString(year)&&checkString(price)){
            try {
                int idCar1=Integer.parseInt(idCar);
                int max_speed1=Integer.parseInt(max_speed);
                int year1=Integer.parseInt(year);
                int price1=Integer.parseInt(price);
                Car c=new Car(idCar1,manufacturer, model, max_speed1, year1, price1);
                service.deleteCar(c);
                carTab1Table.getItems().clear();
                carTab2Table.getItems().clear();
                List<Car> carsTab1= service.getCarRepo().getAll().stream().collect(Collectors.toList());
                carTab1Table.getItems().addAll(carsTab1);
                carTab2Table.getItems().addAll(carsTab1);
                clearFieldsTab1();
                showNotification("Car successfully deleted! ", Alert.AlertType.INFORMATION);
            }catch(ServiceException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }

    public void clearCarFieldsHandler(ActionEvent actionEvent){
        carIDtext.setText("");
        manufacturerCarText.setText("");
        modelCarText.setText("");
        maxSpeedCarText.setText("");
        yearCarText.setText("");
        priceCarText.setText("");
    }


    @FXML
    public void addRentalHandler(ActionEvent actionEvent) {
        String customerName= nameRenterText.getText();
        String date=dateRentalText.getText();
        String no_days=daysRentalText.getText();
        String carID=carIDRentalText.getText();

        if (checkString(customerName)&&checkString(date)&&checkString(no_days)&&checkString(carID)){
            try {
                int no_days1=Integer.parseInt(no_days);
                int carID1=Integer.parseInt(carID);
                int id=service.addRental(customerName, date, no_days1, carID1);
                rentalIDText.setText("" + id);
                rentalTab2Table.getItems().clear();
                List<Rental> rentalTab2 =service.getRentalRepo().getAll().stream().collect(Collectors.toList());
                rentalTab2Table.getItems().addAll(rentalTab2);
                showNotification("Rental successfully added! ", Alert.AlertType.INFORMATION);
            }catch(ServiceException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }catch(NumberFormatException ex){
                showNotification("Please insert numbers where needed!", Alert.AlertType.ERROR);
                carIDRentalText.setText("");
                daysRentalText.setText("");
                return;
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }

    @FXML
    public void updateRentalHandler(ActionEvent actionEvent) {
        String idRental=rentalIDText.getText();
        String customerName= nameRenterText.getText();
        String date=dateRentalText.getText();
        String no_days=daysRentalText.getText();
        String carID=carIDRentalText.getText();

        if (checkString(idRental)&&checkString(customerName)&&checkString(date)&&checkString(no_days)&&checkString(carID)){
            try {
                int idRental1=Integer.parseInt(idRental);
                int no_days1=Integer.parseInt(no_days);
                int carID1=Integer.parseInt(carID);
                Rental r=new Rental(idRental1,customerName, date, no_days1, carID1);
                service.updateRental(r,idRental1);
                rentalTab2Table.getItems().clear();
                List<Rental> rentalTab2 =service.getRentalRepo().getAll().stream().collect(Collectors.toList());
                rentalTab2Table.getItems().addAll(rentalTab2);
                showNotification("Rental successfully updated! ", Alert.AlertType.INFORMATION);
            }catch(ServiceException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }

    @FXML
    public void deleteRentalHandler(ActionEvent actionEvent) {
        String idRental=rentalIDText.getText();
        String customerName= nameRenterText.getText();
        String date=dateRentalText.getText();
        String no_days=daysRentalText.getText();
        String carID=carIDRentalText.getText();

        if (checkString(idRental)&&checkString(customerName)&&checkString(date)&&checkString(no_days)&&checkString(carID)){
            try {
                int idRental1=Integer.parseInt(idRental);
                int no_days1=Integer.parseInt(no_days);
                int carID1=Integer.parseInt(carID);
                Rental r=new Rental(idRental1,customerName, date, no_days1, carID1);
                service.deleteRental(r);
                rentalTab2Table.getItems().clear();
                List<Rental> rentalTab2 =service.getRentalRepo().getAll().stream().collect(Collectors.toList());
                rentalTab2Table.getItems().addAll(rentalTab2);
                clearFieldsTab2();
                showNotification("Rental successfully deleted! ", Alert.AlertType.INFORMATION);
            }catch(ServiceException ex){
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }
        else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }

    public void clearRentalFieldsHandler(ActionEvent actionEvent){
        rentalIDText.setText("");
        nameRenterText.setText("");
        dateRentalText.setText("");
        daysRentalText.setText("");
        carIDRentalText.setText("");
    }


    private void showNotification(String message, Alert.AlertType type){
        Alert alert=new Alert(type);
        alert.setTitle("Notification");
        alert.setContentText(message);
        alert.showAndWait();
    }


    @FXML
    public void searchManufacturerHandler(ActionEvent actionEvent) {
        String searchManufacturer=fByManufacturerText.getText();
        if (!checkString(searchManufacturer)) {
            showNotification("You must introduce a manufacturer! ", Alert.AlertType.ERROR);
            return;
        }
        List<Car> results=service.filterByManufacturer(searchManufacturer);

        if(results.isEmpty())
        {
            showNotification("You must introduce a valid manufacturer! ", Alert.AlertType.ERROR);

            fByManufacturerText.setText("");

            return;
        }
        else {
            carTab3Table.getItems().clear();
            carTab3Table.getItems().addAll(results);
        }
    }

    @FXML
    public void searchModelHandler(ActionEvent actionEvent) {
        String searchModel=fByModelText.getText();
        if (!checkString(searchModel)) {
            showNotification("You must introduce a model! ", Alert.AlertType.ERROR);
            return;
        }
        List<Car> results=service.filterByModel(searchModel);
        if(results.isEmpty())
        {
            showNotification("You must introduce a valid model! ", Alert.AlertType.ERROR);

            fByModelText.setText("");

            return;
        }
        else {
            carTab3Table.getItems().clear();
            carTab3Table.getItems().addAll(results);
        }
    }

    @FXML
    public void searchYearHandler(ActionEvent actionEvent) {
        String searchYear=fUnderYearText.getText();
        if (!checkString(searchYear)) {
            showNotification("You must introduce a year! ", Alert.AlertType.ERROR);
            return;
        }

        try {
            int searchYear1 = Integer.parseInt(searchYear);
            List<Car> results = service.filterByYear(searchYear1);
            if (results.isEmpty()) {
                showNotification("There are no cars made after that year! ", Alert.AlertType.ERROR);

                fUnderYearText.setText("");

                return;
            } else {
                carTab3Table.getItems().clear();
                carTab3Table.getItems().addAll(results);
            }
        }catch(NumberFormatException ex){
            showNotification("Please insert a number!", Alert.AlertType.ERROR);
            fUnderYearText.setText("");

            return;
        }
    }

    @FXML
    public void searchPriceHandler(ActionEvent actionEvent) {
        String searchPrice=fCheaperPriceText.getText();
        if (!checkString(searchPrice)) {
            showNotification("You must introduce a price! ", Alert.AlertType.ERROR);
            return;
        }

        try {
            int searchPrice1 = Integer.parseInt(searchPrice);
            List<Car> results = service.filterCheaperPrice(searchPrice1);
            if (results.isEmpty()) {
                showNotification("There are no cars cheaper than this price! ", Alert.AlertType.ERROR);

                fCheaperPriceText.setText("");

                return;
            } else {
                carTab3Table.getItems().clear();
                carTab3Table.getItems().addAll(results);
            }

        }catch(NumberFormatException ex){
            showNotification("Please insert a number!", Alert.AlertType.ERROR);
            fCheaperPriceText.setText("");

            return;
        }
    }

    @FXML
    public void searchNameHandler(ActionEvent actionEvent) {
        String searchName=fByCustomerText.getText();
        if (!checkString(searchName)) {
            showNotification("You must introduce a name of a customer! ", Alert.AlertType.ERROR);
            return;
        }
        List<Rental> results=service.filterByNameCustomer(searchName);

        if(results.isEmpty())
        {
            showNotification("You must introduce a valid name of a customer! ", Alert.AlertType.ERROR);

            fByCustomerText.setText("");

            return;
        }
        else {
            rentalTab3Table.getItems().clear();
            rentalTab3Table.getItems().addAll(results);
        }
    }

    @FXML
    public void searchDateHandler(ActionEvent actionEvent) {
        String searchDate=fByDateText.getText();
        if (!checkString(searchDate)) {
            showNotification("You must introduce a date! ", Alert.AlertType.ERROR);
            return;
        }
        List<Rental> results=service.filterByDate(searchDate);
        if(results.isEmpty())
        {
            showNotification("You must introduce a valid date! ", Alert.AlertType.ERROR);

            fByDateText.setText("");

            return;
        }
        else {
            rentalTab3Table.getItems().clear();
            rentalTab3Table.getItems().addAll(results);
        }
    }

    @FXML
    public void searchNrDaysHandler(ActionEvent actionEvent) {
        String searchNrDays=fUnderNrDaysText.getText();
        if (!checkString(searchNrDays)) {
            showNotification("You must introduce a number of days! ", Alert.AlertType.ERROR);
            return;
        }

        try {
            int searchNrDays1 = Integer.parseInt(searchNrDays);

            List<Rental> results = service.filterByNoDays(searchNrDays1);
            if (results.isEmpty()) {
                showNotification("There are no rentals with less days of rental! ", Alert.AlertType.ERROR);

                fUnderNrDaysText.setText("");

                return;
            } else {
                rentalTab3Table.getItems().clear();
                rentalTab3Table.getItems().addAll(results);
            }

        }catch(NumberFormatException ex){
            showNotification("Please insert a number!", Alert.AlertType.ERROR);
            fUnderNrDaysText.setText("");

            return;
        }

    }

    @FXML
    public void clearFieldsFilterTextManufacturer(KeyEvent keyEvent){
        fByModelText.setText("");
        fUnderYearText.setText("");
        fCheaperPriceText.setText("");
        fByCustomerText.setText("");
        fByDateText.setText("");
        fUnderNrDaysText.setText("");
    }

    @FXML
    public void clearFieldsFilterTextModel(KeyEvent keyEvent){
        fByManufacturerText.setText("");
        fUnderYearText.setText("");
        fCheaperPriceText.setText("");
        fByCustomerText.setText("");
        fByDateText.setText("");
        fUnderNrDaysText.setText("");
    }

    @FXML
    public void clearFieldsFilterTextYear(KeyEvent keyEvent){
        fByManufacturerText.setText("");
        fByModelText.setText("");
        fCheaperPriceText.setText("");
        fByCustomerText.setText("");
        fByDateText.setText("");
        fUnderNrDaysText.setText("");
    }

    @FXML
    public void clearFieldsFilterTextPrice(KeyEvent keyEvent){
        fByManufacturerText.setText("");
        fByModelText.setText("");
        fUnderYearText.setText("");
        fByCustomerText.setText("");
        fByDateText.setText("");
        fUnderNrDaysText.setText("");
    }

    @FXML
    public void clearFieldsFilterTextCustomer(KeyEvent keyEvent){
        fByManufacturerText.setText("");
        fByModelText.setText("");
        fUnderYearText.setText("");
        fCheaperPriceText.setText("");
        fByDateText.setText("");
        fUnderNrDaysText.setText("");
    }

    @FXML
    public void clearFieldsTextDate(KeyEvent keyEvent)
    {
        fByManufacturerText.setText("");
        fByModelText.setText("");
        fUnderYearText.setText("");
        fCheaperPriceText.setText("");
        fByCustomerText.setText("");
        fUnderNrDaysText.setText("");
    }

    @FXML
    public void clearFieldsTextDays(KeyEvent keyEvent)
    {
        fByManufacturerText.setText("");
        fByModelText.setText("");
        fUnderYearText.setText("");
        fCheaperPriceText.setText("");
        fByCustomerText.setText("");
        fByDateText.setText("");
    }


    static CarRentalService getService(){
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("files.properties"));
            String CarFileName=properties.getProperty("CarFile");
            if (CarFileName==null){ //the property does not exist in the file
                CarFileName="inCar.txt";
                System.err.println("Requests file not found. Using default"+CarFileName);
            }
            String RentalFileName=properties.getProperty("RentalFile");
            if (RentalFileName==null){
                RentalFileName="inRental.txt";
                System.err.println("RepairedForms file not found. Using default"+RentalFileName);
            }
            CarFileRepo carRepoProp = new CarFileRepo(CarFileName);
            RentalFileRepo rentalRepoProp = new RentalFileRepo(RentalFileName,carRepoProp);
            CarRentalService s=new CarRentalService(carRepoProp,rentalRepoProp);
            return s;
        }catch (IOException ex){
            System.err.println("Error reading the configuration file"+ex);
        }
        return null;
    }


}
