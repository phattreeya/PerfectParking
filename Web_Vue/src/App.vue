<template>
  <div id="app">
    
    <h1 id="topic">PERFECT-PARKING</h1>
    <div class="container">
      <div class="row">
        <div class="col">
          <hr>
        </div>
      </div>

      <div class="row">


      </div>

      <div class="row">
        <!--กล่องปุ่มควบคุม-->
        <!-- <control-card name="Light" path="light" :image="require('./assets/light.png')"/>
        <control-card name="Test" path="test" :image="require('./assets/light.png')"/>
        <control-card name="Tests" path="tests" :image="require('./assets/light.png')"/> -->
        <!--กล่องปุ่มควบคุม-->

        <!-- CarCard najaa -->
        <car-card name="Park_1" @isParked="totalHandler" path="Park_1" :image="require('./assets/car.png')"/>
        <car-card name="Park_2" @isParked="totalHandler" path="Park_2" :image="require('./assets/car.png')"/>
        <car-card name="Park_3" @isParked="totalHandler" path="Park_3" :image="require('./assets/car.png')"/>
        <!-- CarCard najaa -->
      </div>
      
      <div class="row Total">
        <!-- Total Car,Data Card -->
        <weather name="TEMPERATURE" path="temperature" :image="require('./assets/thermometer.png')"/>
        <data-card name="TOTAL CAR" :data="availableLot"/>
        <status-card name="STATUS" path="status"/>   
      </div>
      
     </div>
  </div>
</template>

<script>
import DataCard from '@/components/DataCard'
import ControlCard from '@/components/ControlCard'
import CarCard from '@/components/CarCard'
import Weather from '@/components/Weather'
import StatusCard from '@/components/StatusCard'
export default {
  name: 'app',
  components: {
    DataCard,
    ControlCard,
    CarCard,
    Weather,
    StatusCard
  },
  data () {
    return {
      lots: {},
      availableLot: 0
    }
  },
  methods: {
    totalHandler (path, state) {
      this.lots[path] = state
      this.availableLot = Math.abs(Object.values(this.lots).filter(x => x == false).length - 3)
      this.$forceUpdate()
    }
  }
}
</script>

<style lang="scss">
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin: 60px 0;
  background: rgb(131,58,180);
  background: linear-gradient(180deg, #fe8c00, rgba(253,29,29,1) 0%, rgba(0,0,0,1) 100%);
}
#topic{
  background: #125faf;
  color: #fff;
  font-size: 7.5em;
}
</style>
