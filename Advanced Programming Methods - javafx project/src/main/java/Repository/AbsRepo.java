package Repository;

import model.Identifiable;

import java.util.*;

public abstract class AbsRepo <ID, T extends Identifiable<ID>> implements Repository<ID, T>{
    protected Map<ID,T> M;

    public AbsRepo(){
        M= new HashMap<>();

    }
    public T add(T el){
        if(M.containsKey(el.getID()))
        {
            throw new RepoException("Element already exists!!!"+el);

        }
        else
            M.put(el.getID(),el);
        return el;
    }

    public void delete(T el){
        if(M.containsKey(el.getID()))
            M.remove(el.getID());

    }

    public void update(T el,ID id){
        if(M.containsKey(id))
            M.put(el.getID(),el);
        else
            throw new RepoException("Element doesn’t exist"+id);
    }



    public T findByID( ID id){
        if(M.containsKey(id))
            return M.get(id);
        else
            throw new RepoException("Element doesn't exist"+id);
    }
    public Iterable<T> findAll() {
        return M.values();
    }

    @Override
    public Collection<T> getAll() {
        return M.values();
    }
}
