package Repository;

import model.Car;

import java.io.*;

public class CarFileRepo extends CarInMemoryRepo{

    private String FileName;
    private static int idGenerator=0;
    public CarFileRepo(String s){
        this.FileName=s;
        ReadFromFile();
    }

    private void ReadFromFile(){

        try(BufferedReader br=new BufferedReader(new FileReader(FileName))){
            String line=br.readLine();
            try{
                idGenerator=Integer.parseInt(line);
            }catch (NumberFormatException ex){
                System.err.println("Invalid Value for idGenerator, starting from 0");
            }
            while((line=br.readLine())!=null){
                String[] elems=line.split(";");
                if (elems.length!=6){
                    System.err.println("Invalid line ..."+line);
                    continue;
                }
                try{
                    int id=Integer.parseInt(elems[0]);
                    int year=Integer.parseInt(elems[3]);
                    int price=Integer.parseInt(elems[4]);
                    int speed=Integer.parseInt(elems[5]);
                    Car car=new Car(id,elems[1],elems[2],year,price,speed);
                    super.add(car);
                }catch(NumberFormatException ex){
                    System.err.println("Error converting "+ex);
                }
            }

        }catch(IOException ex){
            throw new RepoException("Error reading "+ex);
        }
    }
    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(FileName)){
            pw.println(idGenerator);
            for(Car car:findAll()){
                pw.println(car.getID()+";"+car.getManufacturer()+";"+car.getModel()+";"+car.getYear()+";"+car.getPrice_of_rental()+";"+car.getMax_speed());
            }
        }catch(IOException ex){
            throw new RepoException("Error writing "+ex);
        }

    }


    @Override
    public Car add(Car el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }

    @Override
    public void delete(Car el) {
        super.delete(el);
        writeToFile();
    }

    @Override
    public void update(Car el, Integer integer) {
        super.update(el, integer);
        writeToFile();
    }

    private static int getNextId(){
        return idGenerator++;
    }
}
